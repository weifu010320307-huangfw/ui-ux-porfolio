#ifndef EQULIZERPAGE_H
#define EQULIZERPAGE_H

#include <QDialog>

class QSettings;

namespace Ui {
class equlizerPage;
}

class equlizerPage : public QDialog
{
    Q_OBJECT

public:
    explicit equlizerPage(QWidget *parent = nullptr);
    ~equlizerPage();

    void translateUI();
    void saveEqualizerSetting(QSettings* pSettings);
    void loadEqualizerSetting(QSettings* pSettings);
    void readConfiguration();

private slots:
    void on_resetButton_clicked();

    void on_enableEQButton_clicked();

    void on_enable3DButton_clicked();


    void on_verticalSlider1_valueChanged(int value);

    void on_verticalSlider2_valueChanged(int value);

    void on_verticalSlider3_valueChanged(int value);

    void on_verticalSlider4_valueChanged(int value);

    void on_verticalSlider5_valueChanged(int value);

    void on_verticalSlider6_valueChanged(int value);

    void on_verticalSlider7_valueChanged(int value);

    void on_verticalSlider8_valueChanged(int value);

    void on_verticalSlider9_valueChanged(int value);

    void on_verticalSlider10_valueChanged(int value);

    void bbh_slider_freq_value(void);



    void on_setting1Button_clicked();

    void on_setting2Button_clicked();

private:
    Ui::equlizerPage *ui;
};

#endif // EQULIZERPAGE_H
