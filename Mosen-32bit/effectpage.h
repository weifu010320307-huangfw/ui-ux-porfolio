#ifndef EFFECTPAGE_H
#define EFFECTPAGE_H

#include <QDialog>

class QSettings;

namespace Ui {
class effectPage;
}

class effectPage : public QDialog
{
    Q_OBJECT

public:
    explicit effectPage(QWidget *parent = nullptr);
    ~effectPage();

    void drawPageBackground(QString& strPictureName);
    void saveEffectSetting(QSettings* pSettings);
    void loadEffectSetting(QSettings* pSettings);
    void translateUI();

private slots:
    void on_theaterEffectButton_clicked();

    void on_bathRoomEffectButton_clicked();

    void on_outdoorEffectButton_clicked();

    void on_livingRoomEffectButton_clicked();

    void on_noEffectButton_clicked();



private:
    Ui::effectPage *ui;
};

#endif // EFFECTPAGE_H
