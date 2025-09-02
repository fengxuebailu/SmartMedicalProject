#include "relaxationdialog.h"
#include "ui_relaxationdialog.h"
#include <QMediaContent>
#include <QMediaContent>
#include <QCoreApplication>

RelaxationDialog::RelaxationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RelaxationDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("放松小岛");

    // 1. 初始化播放器和播放列表
    m_player = new QMediaPlayer(this);
    m_playlist = new QMediaPlaylist(m_player);
    m_player->setPlaylist(m_playlist);

    // 2. 将视频内容输出到 QVideoWidget 上
    m_player->setVideoOutput(ui->videoPlayerPlaceholder);

    // 3. 添加舒缓内容到播放列表
    QString appDirPath = QCoreApplication::applicationDirPath();

    // 添加你的新视频和音频文件
    QString videoPath1 = appDirPath + "/media/videos/video_1.mp4"; // 请确保文件名匹配
    QString videoPath2 = appDirPath + "/media/videos/video_1.mp4"; // 请确保文件名匹配
    QString musicPath1 = appDirPath + "/media/music/music_2.mp3"; // 请确保文件名匹配
    QString musicPath2 = appDirPath + "/media/music/music_2.mp3"; // 请确保文件名匹配

    qDebug() << "Attempting to load video from:" << videoPath1;
    qDebug() << "Attempting to load music from:" << musicPath1;

    // 使用 QUrl::fromLocalFile 从本地文件路径创建 QUrl
    m_playlist->addMedia(QMediaContent(QUrl::fromLocalFile(videoPath1)));
    m_playlist->addMedia(QMediaContent(QUrl::fromLocalFile(musicPath1)));
    m_playlist->addMedia(QMediaContent(QUrl::fromLocalFile(videoPath2)));
    m_playlist->addMedia(QMediaContent(QUrl::fromLocalFile(musicPath2)));

    m_playlist->setPlaybackMode(QMediaPlaylist::Loop); // 设置循环播放

    // 4. 连接信号和槽，例如更新进度条、播放状态改变等
    // connect(m_player, &QMediaPlayer::positionChanged, ...);

    // 5. 自动开始播放
    m_player->play();
}

RelaxationDialog::~RelaxationDialog()
{
    delete ui;
}

void RelaxationDialog::on_playPauseButton_clicked()
{
    if (m_player->state() == QMediaPlayer::PlayingState) {
        m_player->pause();
        // 更新按钮图标为“播放”
    } else {
        m_player->play();
        // 更新按钮图标为“暂停”
    }
}

void RelaxationDialog::on_nextButton_clicked()
{
    // 如果播放列表不为空，就播放下一个媒体项
    if (m_playlist && m_playlist->mediaCount() > 0) {
        m_playlist->next();
    }
}
// ...
