#ifndef RELAXATIONDIALOG_H
#define RELAXATIONDIALOG_H

#include <QDialog>
#include <QMediaPlayer> // 包含头文件
#include <QMediaPlaylist>

namespace Ui {
class RelaxationDialog;
}

class RelaxationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RelaxationDialog(QWidget *parent = nullptr);
    ~RelaxationDialog();

private slots:
    void on_playPauseButton_clicked();
    void on_nextButton_clicked();
    // ... 其他槽函数，如处理进度条拖动 ...

private:
    Ui::RelaxationDialog *ui;
    QMediaPlayer *m_player;
    QMediaPlaylist *m_playlist;
};
#endif // RELAXATIONDIALOG_H
