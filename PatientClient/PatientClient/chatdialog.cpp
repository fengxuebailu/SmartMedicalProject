#include "chatdialog.h".h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QDateTime>

static const QUrl kZhipuURL("https://open.bigmodel.cn/api/paas/v4/chat/completions");

ChatWindow::ChatWindow(QWidget *p): QMainWindow(p){
    auto *w = new QWidget(this); setCentralWidget(w);
    m_list = new QListWidget(this); m_list->setWordWrap(true);
    m_input = new QTextEdit(this);  m_input->setPlaceholderText("输入要问AI诊断助手的问题…");
    m_input->setFixedHeight(120);
    m_send  = new QPushButton("发送", this);
    m_model = new QComboBox(this);  m_model->addItems({"glm-4-flash","glm-4-air","glm-4"});
    auto *top = new QHBoxLayout; top->addWidget(new QLabel("模型：")); top->addWidget(m_model,1);
    auto *lay = new QVBoxLayout(w); lay->addLayout(top); lay->addWidget(m_list,1); lay->addWidget(m_input); lay->addWidget(m_send);
    append("系统","已切换为智谱 GLM 对话接口。请设置环境变量 BIGMODEL_API_KEY。");
    connect(m_send,&QPushButton::clicked,this,&ChatWindow::sendMessage);
}

void ChatWindow::append(const QString& who,const QString& text){
    auto *it=new QListWidgetItem(QString("[%1] %2\n\n%3")
        .arg(QDateTime::currentDateTime().toString("HH:mm:ss")).arg(who).arg(text));
    it->setTextAlignment(who=="我"?Qt::AlignRight:Qt::AlignLeft);
    m_list->addItem(it); m_list->scrollToBottom();
}

QByteArray ChatWindow::buildBody(const QString& userText) const{
    QJsonArray msgs; msgs.append(QJsonObject{{"role","user"},{"content",userText}});
    QJsonObject body{{"model", m_model->currentText()}, {"messages", msgs}};
    return QJsonDocument(body).toJson(QJsonDocument::Compact);
}

void ChatWindow::sendMessage(){
    const QString text=m_input->toPlainText().trimmed(); if(text.isEmpty()) return;
    append("我", text); m_input->clear();

    const QByteArray key=qgetenv("BIGMODEL_API_KEY");
    if(key.isEmpty()){ QMessageBox::warning(this,"未设置","请 export BIGMODEL_API_KEY=你的Key"); return; }

    QNetworkRequest req(kZhipuURL);
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    req.setRawHeader("Authorization","Bearer "+key);

    auto *rp = m_nam.post(req, buildBody(text));
    m_send->setEnabled(false);
    connect(rp,&QNetworkReply::finished,this,&ChatWindow::handleReply);
}

void ChatWindow::handleReply(){
    auto *rp=qobject_cast<QNetworkReply*>(sender()); m_send->setEnabled(true); if(!rp) return;
    const QByteArray buf=rp->readAll();
    if(rp->error()){
        append("错误", QString("HTTP %1 %2\n%3")
            .arg(rp->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt())
            .arg(rp->errorString()).arg(QString::fromUtf8(buf)));
        rp->deleteLater(); return;
    }
    // 解析：choices[0].message.content
    QJsonDocument jd=QJsonDocument::fromJson(buf);
    auto choices=jd.object().value("choices").toArray();
    QString content;
    if(!choices.isEmpty()){
        content = choices[0].toObject().value("message").toObject().value("content").toString();
    }
    if(content.isEmpty()) content = QString::fromUtf8(buf); // 兜底
    append("智谱", content);
    rp->deleteLater();
}
