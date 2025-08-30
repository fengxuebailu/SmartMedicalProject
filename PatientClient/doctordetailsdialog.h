#ifndef DOCTORDETAILSDIALOG_H
#define DOCTORDETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class DoctorDetailsDialog;
}

class DoctorDetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorDetailsDialog(QWidget *parent = nullptr);
    ~DoctorDetailsDialog();

    // 公共方法，用于从外部传入医生ID并加载其详细信息
    void loadDoctorDetails(int doctorId);

private slots:
    void on_closeButton_clicked();

private:
    Ui::DoctorDetailsDialog *ui;
};

#endif // DOCTORDETAILSDIALOG_H
