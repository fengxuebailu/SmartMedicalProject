#include "timeselectiondialog.h"
#include "ui_timeselectiondialog.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <QSet>

TimeSelectionDialog::TimeSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeSelectionDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("第二步：选择预约时间");

    ui->calendarWidget->setMinimumDate(QDate::currentDate());
}

TimeSelectionDialog::~TimeSelectionDialog()
{
    delete ui;
}

void TimeSelectionDialog::setAppointmentInfo(int doctorId, const QString &doctorName, int patientId)
{
    m_doctorId = doctorId;
    m_patientId = patientId;
    ui->doctorInfoLabel->setText(QString("您正在为【%1】医生进行预约").arg(doctorName));
    updateAvailableTimes(ui->calendarWidget->selectedDate()); // 初始加载当天的时间
}

// 新的核心函数：更新可用时间
void TimeSelectionDialog::updateAvailableTimes(const QDate &date)
{
    ui->timeSlotsListWidget->clear();
    ui->confirmButton->setEnabled(false);

    // 1. 定义医生一天的工作时间段 (假设上午9-12，下午14-17，每小时一个号)
    QList<QTime> workingHours;
    for (int h = 9; h < 12; ++h) workingHours.append(QTime(h, 0));
    for (int h = 14; h < 17; ++h) workingHours.append(QTime(h, 0));

    // 2. 查询当天已被预约的时间
    QSet<QTime> bookedTimes;
    QSqlQuery query;
    query.prepare("SELECT scheduled_at FROM appointments "
                  "WHERE doctor_id = :doctorId AND DATE(scheduled_at) = :selectedDate "
                  "AND status IN ('booked', 'completed')");
    query.bindValue(":doctorId", m_doctorId);
    query.bindValue(":selectedDate", date.toString(Qt::ISODate));

    if (!query.exec()) {
        qDebug() << "查询已预约时间失败: " << query.lastError().text();
        return;
    }
    while (query.next()) {
        bookedTimes.insert(query.value(0).toDateTime().time());
    }

    // 3. 将未被预约的时间段添加到列表中
    for (const QTime &time : workingHours) {
        if (!bookedTimes.contains(time)) {
            ui->timeSlotsListWidget->addItem(time.toString("HH:mm"));
        }
    }

    if (ui->timeSlotsListWidget->count() == 0) {
        ui->timeSlotsListWidget->addItem("本日已约满或无排班");
        ui->timeSlotsListWidget->setEnabled(false);
    } else {
        ui->timeSlotsListWidget->setEnabled(true);
    }
}


void TimeSelectionDialog::on_calendarWidget_clicked(const QDate &date)
{
    updateAvailableTimes(date);
}

void TimeSelectionDialog::on_timeSlotsListWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() != "本日已约满或无排班") {
        ui->confirmButton->setEnabled(true);
    }
}

void TimeSelectionDialog::on_confirmButton_clicked()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    if (!ui->timeSlotsListWidget->currentItem()) {
        QMessageBox::warning(this, "提示", "请选择一个预约时间点。");
        return;
    }
    QTime selectedTime = QTime::fromString(ui->timeSlotsListWidget->currentItem()->text(), "HH:mm");
    QDateTime scheduledAt(selectedDate, selectedTime);

    QSqlQuery query;
    // 新的 INSERT 语句，适配 appointments 表
    query.prepare("INSERT INTO appointments (patient_id, doctor_id, scheduled_at, status) "
                  "VALUES (:patientId, :doctorId, :scheduledAt, 'booked')");
    query.bindValue(":patientId", m_patientId);
    query.bindValue(":doctorId", m_doctorId);
    query.bindValue(":scheduledAt", scheduledAt);

    if (query.exec()) {
        QMessageBox::information(this, "预约成功",
                                 QString("您已成功预约！\n\n时间: %1\n\n请在“我的预约”中查看详情。")
                                 .arg(scheduledAt.toString("yyyy-MM-dd HH:mm")));
        this->accept();
    } else {
        QMessageBox::critical(this, "预约失败", "无法完成预约，数据库错误: " + query.lastError().text());
    }
}
