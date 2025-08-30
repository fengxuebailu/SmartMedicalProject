#ifndef TIMESELECTIONDIALOG_H
#define TIMESELECTIONDIALOG_H

#include <QDialog>
#include <QDate>
#include <QListWidgetItem>

namespace Ui {
class TimeSelectionDialog;
}

class TimeSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeSelectionDialog(QWidget *parent = nullptr);
    ~TimeSelectionDialog();

    // 公共函数，用于接收开启此对话框时传入的必要信息
    void setAppointmentInfo(int doctorId, const QString &doctorName, int patientId);

private slots:
    // 当日历上的日期被点击时触发
    void on_calendarWidget_clicked(const QDate &date);
    // 当时间段列表中的某一项被点击时触发
    void on_timeSlotsListWidget_itemClicked(QListWidgetItem *item);
    // 当“确认预约”按钮被点击时触发
    void on_confirmButton_clicked();

private:
    Ui::TimeSelectionDialog *ui;

    // 存储从上一个流程传入的信息
    int m_doctorId;
    int m_patientId;
};

#endif // TIMESELECTIONDIALOG_H
