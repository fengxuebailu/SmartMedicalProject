#ifndef PATIENTINFODIALOG_H
#define PATIENTINFODIALOG_H

#include <QDialog>

namespace Ui {
class PatientInfoDialog;
}

class PatientInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientInfoDialog(QWidget *parent = nullptr);
    ~PatientInfoDialog();

private:
    // 添加一个私有方法用于加载数据
    void loadPatientData(int patientId);

private slots:
    // “关闭”按钮的槽函数
    void on_closeButton_clicked();

    void on_editSaveButton_clicked();

private:
    Ui::PatientInfoDialog *ui;
    bool m_isEditMode;      // <-- 添加这一行，用于跟踪编辑状态
    int m_patientId;        // <-- 添加这一行，用于记住当前患者ID
};

#endif // PATIENTINFODIALOG_H
