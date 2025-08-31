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

    void setAppointmentInfo(int doctorId, const QString &doctorName, int patientId);

private slots:
    void on_calendarWidget_clicked(const QDate &date);
    void on_timeSlotsListWidget_itemClicked(QListWidgetItem *item);
    void on_confirmButton_clicked();

private:
    void updateAvailableTimes(const QDate &date);

    Ui::TimeSelectionDialog *ui;

    int m_doctorId;
    int m_patientId;
};

#endif // TIMESELECTIONDIALOG_H
