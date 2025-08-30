#ifndef DOCTORSELECTIONDIALOG_H
#define DOCTORSELECTIONDIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#include <QMap>

namespace Ui {
class DoctorSelectionDialog;
}

class DoctorSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorSelectionDialog(QWidget *parent = nullptr);
    ~DoctorSelectionDialog();

signals:
    // 自定义信号：当用户选择完医生并点击“下一步”时发射
    // 参数1: 选中的医生ID
    // 参数2: 选中的医生姓名
    void doctorSelected(int doctorId, const QString &doctorName);

private slots:
    // 当左侧科室列表中的某一项被点击时触发
    void on_departmentsListWidget_itemClicked(QListWidgetItem *item);
    // 当右侧医生表格中的某个单元格被点击时触发
    void on_doctorsTableWidget_cellClicked(int row, int column);
    // 当“下一步”按钮被点击时触发
    void on_nextButton_clicked();

private:
    // 私有辅助函数
    void loadDepartments();
    void loadDoctors(int departmentId);

    Ui::DoctorSelectionDialog *ui;

    // 用于存储科室名称和其对应的数据库ID
    QMap<QString, int> m_departmentIdMap;

    // 用于临时存储用户选中的医生信息
    int m_selectedDoctorId;
    QString m_selectedDoctorName;
};

#endif // DOCTORSELECTIONDIALOG_H
