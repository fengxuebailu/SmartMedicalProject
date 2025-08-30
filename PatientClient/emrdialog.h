#ifndef EMRDIALOG_H
#define EMRDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QMap>

namespace Ui {
class EmrDialog;
}

class EmrDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmrDialog(QWidget *parent = nullptr);
    ~EmrDialog();

    void loadPatientRecords(int patientId);

private slots:
    void on_visitsListWidget_itemClicked(QListWidgetItem *item);
    void on_closeButton_clicked();

private:
    void displayRecordDetails(int recordId);
    void clearDetails();

    Ui::EmrDialog *ui;
    int m_patientId;
    // 使用 QMap 来存储列表项指针和其对应的病历ID
    QMap<QListWidgetItem*, int> m_recordIdMap;
};

#endif // EMRDIALOG_H
