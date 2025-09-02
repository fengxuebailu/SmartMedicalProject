#pragma once
#include <QDialog>

class QCheckBox;
class QLineEdit;
class QLabel;

class HealthCheckinDialog : public QDialog {
    Q_OBJECT
public:
    explicit HealthCheckinDialog(QWidget* parent = nullptr);
    void setUserId(qulonglong uid) { userId_ = uid; }   // 外部传入当前用户ID

signals:
    void checkinSaved();

private slots:
    void onSave();

private:
    int calculateStars(bool diet, bool exercise, bool med) const;

    qulonglong userId_ = 0;
    QCheckBox* cbDiet_ = nullptr;
    QCheckBox* cbExercise_ = nullptr;
    QCheckBox* cbMed_ = nullptr;
    QLineEdit*  noteEdit_ = nullptr;
    QLabel*     tip_ = nullptr;
};
