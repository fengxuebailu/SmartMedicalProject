// Aidialog.h
#pragma once
#include <QMainWindow>
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QNetworkAccessManager>

class Aidialog : public QMainWindow {   // ← 改名
    Q_OBJECT
public:
    explicit Aidialog(QWidget *parent=nullptr);
private slots:
    void sendMessage();
    void handleReply();
private:
    QByteArray buildBody(const QString& userText) const;
    void append(const QString& who, const QString& text);
    QListWidget *m_list{};
    QTextEdit *m_input{};
    QPushButton *m_send{};
    QComboBox *m_model{};
    QNetworkAccessManager m_nam;
};
