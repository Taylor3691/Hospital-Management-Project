/********************************************************************************
** Form generated from reading UI file 'RoomView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMVIEW_H
#define UI_ROOMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomView
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *id_label;
    QLabel *name_label;
    QFrame *line;
    QLabel *recordList_label;
    QVBoxLayout *verticalLayout;
    QRadioButton *waiting_radioButton;
    QRadioButton *finished_radioButton;
    QRadioButton *allRecords_radioButton;
    QListView *record_listView;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *recordId_label;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *patientId_label;
    QLineEdit *patientId_lineEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *doctorName_label;
    QLineEdit *doctorName_lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *primaryDiagnose_label;
    QLineEdit *primaryDiagnose_lineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *secondaryDiagnose_label;
    QLineEdit *secondaryDiagnose_lineEdit;
    QDialogButtonBox *buttonBox;
    QFrame *line_2;
    QTabWidget *tabWidget;
    QWidget *patientInfo_tab;
    QHBoxLayout *horizontalLayout_20;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *personalInfo_groupBox;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_31;
    QLabel *patientId_label_2;
    QLineEdit *patientId_lineEdit_2;
    QHBoxLayout *horizontalLayout_32;
    QLabel *patientName_label;
    QLineEdit *patientName_lineEdit_3;
    QHBoxLayout *horizontalLayout_33;
    QLabel *gender_label;
    QComboBox *gender_comboBox;
    QHBoxLayout *horizontalLayout_34;
    QLabel *dob_label;
    QDateEdit *dob_dateEdit;
    QHBoxLayout *horizontalLayout_35;
    QLabel *phone_label;
    QLineEdit *phone_lineEdit;
    QHBoxLayout *horizontalLayout_36;
    QLabel *address_label;
    QLineEdit *address_lineEdit;
    QFrame *symptom_frame;
    QHBoxLayout *horizontalLayout_41;
    QLabel *symptom_label;
    QPlainTextEdit *symptom_plainTextEdit;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *insuranceInfo_groupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_38;
    QLabel *cardId_label;
    QLineEdit *cardId_lineEdit;
    QHBoxLayout *horizontalLayout_37;
    QLabel *issueDate_label;
    QDateEdit *issueDate_dateEdit;
    QHBoxLayout *horizontalLayout_39;
    QLabel *expiryDate_label;
    QDateEdit *expiryDate_dateEdit;
    QHBoxLayout *horizontalLayout_40;
    QLabel *coveragePercent_label;
    QDoubleSpinBox *coveragePercent_doubleSpinBox;
    QWidget *paraclinicalSpecifying_tab;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_42;
    QLabel *quickSpecify_label;
    QComboBox *quickSpecify_comboBox;
    QTableView *specifiedTests_tableView;
    QWidget *precribe_tab;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_45;
    QHBoxLayout *horizontalLayout_44;
    QLabel *precribedDate_label;
    QDateEdit *precribedDate_dateEdit;
    QHBoxLayout *horizontalLayout_43;
    QLabel *precribingDoctorName_label;
    QLineEdit *precribingDoctorName_lineEdit;
    QPushButton *quickPrecribe_pushButton;
    QTableWidget *precibedMedicines_tableWidget;

    void setupUi(QWidget *RoomView)
    {
        if (RoomView->objectName().isEmpty())
            RoomView->setObjectName(QString::fromUtf8("RoomView"));
        RoomView->resize(1065, 636);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RoomView->sizePolicy().hasHeightForWidth());
        RoomView->setSizePolicy(sizePolicy);
        RoomView->setMinimumSize(QSize(512, 288));
        RoomView->setStyleSheet(QString::fromUtf8("/* ---------------------------------------------------------------------------\n"
"\n"
"    WARNING! File created programmatically. All changes made in this file will be lost!\n"
"\n"
"    Created by the qtsass compiler v0.4.0\n"
"\n"
"    The definitions are in the \"qdarkstyle.qss._styles.scss\" module\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"/* Light Style - QDarkStyleSheet ------------------------------------------ */\n"
"/*\n"
"\n"
"See Qt documentation:\n"
"\n"
"  - https://doc.qt.io/qt-5/stylesheet.html\n"
"  - https://doc.qt.io/qt-5/stylesheet-reference.html\n"
"  - https://doc.qt.io/qt-5/stylesheet-examples.html\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"/* Reset elements ------------------------------------------------------------\n"
"\n"
"Resetting everything helps to unify styles across different operating systems\n"
"\n"
"--------------------------------------------------------------------------- */"
                        "\n"
"* {\n"
"  padding: 0px;\n"
"  margin: 0px;\n"
"  border: 0px;\n"
"  border-style: none;\n"
"  border-image: none;\n"
"  outline: 0;\n"
"  font: 9pt \"Segoe UI\";\n"
"}\n"
"\n"
"/* specific reset for elements inside QToolBar */\n"
"QToolBar * {\n"
"  margin: 0px;\n"
"  padding: 0px;\n"
"}\n"
"\n"
"/* QWidget ----------------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QWidget {\n"
"  background-color: #FAFAFA;\n"
"  border: 0px solid #C0C4C8;\n"
"  padding: 0px;\n"
"  color: #19232D;\n"
"  selection-background-color: #9FCBFF;\n"
"  selection-color: #19232D;\n"
"}\n"
"\n"
"QWidget:disabled {\n"
"  background-color: #FAFAFA;\n"
"  color: #9DA9B5;\n"
"  selection-background-color: #DAEDFF;\n"
"  selection-color: #9DA9B5;\n"
"}\n"
"\n"
"QWidget::item:selected {\n"
"  background-color: #9FCBFF;\n"
"}\n"
"\n"
"QWidget::item:hover:!selected {\n"
"  background-color: #73C7FF;\n"
"}\n"
"\n"
"/* QMainWindow --------------"
                        "----------------------------------------------\n"
"\n"
"This adjusts the splitter in the dock widget, not qsplitter\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qmainwindow\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QMainWindow::separator {\n"
"  background-color: #C0C4C8;\n"
"  border: 0px solid #FAFAFA;\n"
"  spacing: 0px;\n"
"  padding: 2px;\n"
"}\n"
"\n"
"QMainWindow::separator:hover {\n"
"  background-color: #ACB1B6;\n"
"  border: 0px solid #73C7FF;\n"
"}\n"
"\n"
"QMainWindow::separator:horizontal {\n"
"  width: 5px;\n"
"  margin-top: 2px;\n"
"  margin-bottom: 2px;\n"
"  image: url(\":/qss_icons/light/rc_light/toolbar_separator_vertical.png\");\n"
"}\n"
"\n"
"QMainWindow::separator:vertical {\n"
"  height: 5px;\n"
"  margin-left: 2px;\n"
"  margin-right: 2px;\n"
"  image: url(\":/qss_icons/light/rc_light/toolbar_separator_horizontal.png\");\n"
"}\n"
"\n"
"/* QToolTip ---------------------------------------------------------------\n"
"\n"
""
                        "https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtooltip\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QToolTip {\n"
"  background-color: #9FCBFF;\n"
"  color: #19232D;\n"
"  /* If you remove the border property, background stops working on Windows */\n"
"  border: none;\n"
"  /* Remove padding, for fix combo box tooltip */\n"
"  padding: 0px;\n"
"  /* Remove opacity, fix #174 - may need to use RGBA */\n"
"}\n"
"\n"
"/* QStatusBar -------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qstatusbar\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QStatusBar {\n"
"  border: 1px solid #C0C4C8;\n"
"  /* Fixes Spyder #9120, #9121 */\n"
"  background: #C0C4C8;\n"
"  /* Fixes #205, white vertical borders separating items */\n"
"}\n"
"\n"
"QStatusBar::item {\n"
"  border: none;\n"
"}\n"
"\n"
"QStatusBar QToolTip {\n"
"  background-color: #73C7FF;"
                        "\n"
"  border: 1px solid #FAFAFA;\n"
"  color: #FAFAFA;\n"
"  /* Remove padding, for fix combo box tooltip */\n"
"  padding: 0px;\n"
"  /* Reducing transparency to read better */\n"
"  opacity: 230;\n"
"}\n"
"\n"
"QStatusBar QLabel {\n"
"  /* Fixes Spyder #9120, #9121 */\n"
"  background: transparent;\n"
"}\n"
"\n"
"/* QCheckBox --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qcheckbox\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QCheckBox {\n"
"  background-color: #FAFAFA;\n"
"  color: #19232D;\n"
"  spacing: 4px;\n"
"  outline: none;\n"
"  padding-top: 4px;\n"
"  padding-bottom: 4px;\n"
"}\n"
"\n"
"QCheckBox:focus {\n"
"  border: none;\n"
"}\n"
"\n"
"QCheckBox QWidget:disabled {\n"
"  background-color: #FAFAFA;\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"  margin-left: 2px;\n"
"  height: 14px;\n"
"  width: 14px;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
""
                        "  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover, QCheckBox::indicator:unchecked:focus, QCheckBox::indicator:unchecked:pressed {\n"
"  border: none;\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked_focus.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked_disabled.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:hover, QCheckBox::indicator:checked:focus, QCheckBox::indicator:checked:pressed {\n"
"  border: none;\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked_focus.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:checked:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked_disabled.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_inde"
                        "terminate.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_indeterminate_disabled.png\");\n"
"}\n"
"\n"
"QCheckBox::indicator:indeterminate:focus, QCheckBox::indicator:indeterminate:hover, QCheckBox::indicator:indeterminate:pressed {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_indeterminate_focus.png\");\n"
"}\n"
"\n"
"/* QGroupBox --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qgroupbox\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QGroupBox {\n"
"  font-weight: bold;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"  padding: 2px;\n"
"  margin-top: 6px;\n"
"  margin-bottom: 4px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"  subcontrol-origin: margin;\n"
"  subcontrol-position: top left;\n"
"  left: 4px;\n"
"  padding-left: 2px;\n"
"  padding-right: 4px;\n"
"  padding-top: -4px;\n"
"}\n"
""
                        "\n"
"QGroupBox::indicator {\n"
"  margin-left: 2px;\n"
"  margin-top: 2px;\n"
"  padding: 0;\n"
"  height: 14px;\n"
"  width: 14px;\n"
"}\n"
"\n"
"QGroupBox::indicator:unchecked {\n"
"  border: none;\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked.png\");\n"
"}\n"
"\n"
"QGroupBox::indicator:unchecked:hover, QGroupBox::indicator:unchecked:focus, QGroupBox::indicator:unchecked:pressed {\n"
"  border: none;\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked_focus.png\");\n"
"}\n"
"\n"
"QGroupBox::indicator:unchecked:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked_disabled.png\");\n"
"}\n"
"\n"
"QGroupBox::indicator:checked {\n"
"  border: none;\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked.png\");\n"
"}\n"
"\n"
"QGroupBox::indicator:checked:hover, QGroupBox::indicator:checked:focus, QGroupBox::indicator:checked:pressed {\n"
"  border: none;\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked_focus.png\");\n"
"}\n"
"\n"
"QGroupB"
                        "ox::indicator:checked:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked_disabled.png\");\n"
"}\n"
"\n"
"/* QRadioButton -----------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qradiobutton\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QRadioButton {\n"
"  background-color: #FAFAFA;\n"
"  color: #19232D;\n"
"  spacing: 4px;\n"
"  padding-top: 4px;\n"
"  padding-bottom: 4px;\n"
"  border: none;\n"
"  outline: none;\n"
"}\n"
"\n"
"QRadioButton:focus {\n"
"  border: none;\n"
"}\n"
"\n"
"QRadioButton:disabled {\n"
"  background-color: #FAFAFA;\n"
"  color: #9DA9B5;\n"
"  border: none;\n"
"  outline: none;\n"
"}\n"
"\n"
"QRadioButton QWidget {\n"
"  background-color: #FAFAFA;\n"
"  color: #19232D;\n"
"  spacing: 0px;\n"
"  padding: 0px;\n"
"  outline: none;\n"
"  border: none;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"  border: none;\n"
"  outline: none;\n"
"  margin-left:"
                        " 2px;\n"
"  height: 14px;\n"
"  width: 14px;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"  image: url(\":/qss_icons/light/rc_light/radio_unchecked.png\");\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover, QRadioButton::indicator:unchecked:focus, QRadioButton::indicator:unchecked:pressed {\n"
"  border: none;\n"
"  outline: none;\n"
"  image: url(\":/qss_icons/light/rc_light/radio_unchecked_focus.png\");\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/radio_unchecked_disabled.png\");\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"  border: none;\n"
"  outline: none;\n"
"  image: url(\":/qss_icons/light/rc_light/radio_checked.png\");\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:hover, QRadioButton::indicator:checked:focus, QRadioButton::indicator:checked:pressed {\n"
"  border: none;\n"
"  outline: none;\n"
"  image: url(\":/qss_icons/light/rc_light/radio_checked_focus.png\");\n"
"}\n"
"\n"
"QRadioButton::indicator:checked:disable"
                        "d {\n"
"  outline: none;\n"
"  image: url(\":/qss_icons/light/rc_light/radio_checked_disabled.png\");\n"
"}\n"
"\n"
"/* QMenuBar ---------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qmenubar\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QMenuBar {\n"
"  background-color: #C0C4C8;\n"
"  padding: 2px;\n"
"  border: 1px solid #FAFAFA;\n"
"  color: #19232D;\n"
"  selection-background-color: #73C7FF;\n"
"}\n"
"\n"
"QMenuBar:focus {\n"
"  border: 1px solid #9FCBFF;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"  background: transparent;\n"
"  padding: 4px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"  padding: 4px;\n"
"  background: transparent;\n"
"  border: 0px solid #C0C4C8;\n"
"  background-color: #73C7FF;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"  padding: 4px;\n"
"  border: 0px solid #C0C4C8;\n"
"  background-color: #73C7FF;\n"
"  color: #19232D;\n"
"  margin-bottom: 0px;\n"
"  padding-bottom"
                        ": 0px;\n"
"}\n"
"\n"
"/* QMenu ------------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qmenu\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QMenu {\n"
"  border: 0px solid #C0C4C8;\n"
"  color: #19232D;\n"
"  margin: 0px;\n"
"  background-color: #D2D5D8;\n"
"  selection-background-color: #73C7FF;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"  height: 1px;\n"
"  background-color: #ACB1B6;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QMenu::item {\n"
"  background-color: #D2D5D8;\n"
"  padding: 4px 24px 4px 28px;\n"
"  /* Reserve space for selection border */\n"
"  border: 1px transparent #C0C4C8;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"  color: #19232D;\n"
"  background-color: #73C7FF;\n"
"}\n"
"\n"
"QMenu::item:pressed {\n"
"  background-color: #73C7FF;\n"
"}\n"
"\n"
"QMenu::item:disabled {\n"
"  background-color: #D2D5D8;\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"QMenu::icon {\n"
"  padding-left: 10px;\n"
""
                        "  width: 14px;\n"
"  height: 14px;\n"
"}\n"
"\n"
"QMenu::indicator {\n"
"  padding-left: 8px;\n"
"  width: 12px;\n"
"  height: 12px;\n"
"  /* non-exclusive indicator = check box style indicator (see QActionGroup::setExclusive) */\n"
"  /* exclusive indicator = radio button style indicator (see QActionGroup::setExclusive) */\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:unchecked {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked.png\");\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:unchecked:hover, QMenu::indicator:non-exclusive:unchecked:focus, QMenu::indicator:non-exclusive:unchecked:pressed {\n"
"  border: none;\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked_focus.png\");\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:unchecked:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked_disabled.png\");\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:checked {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked.png\");\n"
"}\n"
"\n"
"QMenu::indicator"
                        ":non-exclusive:checked:hover, QMenu::indicator:non-exclusive:checked:focus, QMenu::indicator:non-exclusive:checked:pressed {\n"
"  border: none;\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked_focus.png\");\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:checked:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked_disabled.png\");\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:indeterminate {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_indeterminate.png\");\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:indeterminate:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_indeterminate_disabled.png\");\n"
"}\n"
"\n"
"QMenu::indicator:non-exclusive:indeterminate:focus, QMenu::indicator:non-exclusive:indeterminate:hover, QMenu::indicator:non-exclusive:indeterminate:pressed {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_indeterminate_focus.png\");\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:unchecked {\n"
"  image: url(\":/qss_icons/light/rc_light/radio"
                        "_unchecked.png\");\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:unchecked:hover, QMenu::indicator:exclusive:unchecked:focus, QMenu::indicator:exclusive:unchecked:pressed {\n"
"  border: none;\n"
"  outline: none;\n"
"  image: url(\":/qss_icons/light/rc_light/radio_unchecked_focus.png\");\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:unchecked:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/radio_unchecked_disabled.png\");\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked {\n"
"  border: none;\n"
"  outline: none;\n"
"  image: url(\":/qss_icons/light/rc_light/radio_checked.png\");\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked:hover, QMenu::indicator:exclusive:checked:focus, QMenu::indicator:exclusive:checked:pressed {\n"
"  border: none;\n"
"  outline: none;\n"
"  image: url(\":/qss_icons/light/rc_light/radio_checked_focus.png\");\n"
"}\n"
"\n"
"QMenu::indicator:exclusive:checked:disabled {\n"
"  outline: none;\n"
"  image: url(\":/qss_icons/light/rc_light/radio_checked_disabled.png\");\n"
"}\n"
"\n"
"QMe"
                        "nu::right-arrow {\n"
"  margin: 5px;\n"
"  padding-left: 12px;\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_right.png\");\n"
"  height: 12px;\n"
"  width: 12px;\n"
"}\n"
"\n"
"/* QAbstractItemView ------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qcombobox\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QAbstractItemView {\n"
"  alternate-background-color: #FAFAFA;\n"
"  color: #19232D;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QAbstractItemView QLineEdit {\n"
"  padding: 2px;\n"
"}\n"
"\n"
"/* QAbstractScrollArea ----------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qabstractscrollarea\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QAbstractScrollArea {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
""
                        "  /* fix #159 */\n"
"  padding: 2px;\n"
"  /* remove min-height to fix #244 */\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QAbstractScrollArea:disabled {\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"/* QScrollArea ------------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QScrollArea QWidget QWidget:disabled {\n"
"  background-color: #FAFAFA;\n"
"}\n"
"\n"
"/* QScrollBar -------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qscrollbar\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QScrollBar:horizontal {\n"
"  height: 16px;\n"
"  margin: 2px 16px 2px 16px;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"  background-color: #FAFAFA;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"  background-color: #FAFAFA;\n"
"  width: 16px;\n"
"  margin: 16px 2px 16px 2px;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-r"
                        "adius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"  background-color: #ACB1B6;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"  min-width: 8px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:hover {\n"
"  background-color: #9FCBFF;\n"
"  border: #9FCBFF;\n"
"  border-radius: 4px;\n"
"  min-width: 8px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"  background-color: #ACB1B6;\n"
"  border: 1px solid #C0C4C8;\n"
"  min-height: 8px;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"  background-color: #9FCBFF;\n"
"  border: #9FCBFF;\n"
"  border-radius: 4px;\n"
"  min-height: 8px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"  margin: 0px 0px 0px 0px;\n"
"  border-image: url(\":/qss_icons/light/rc_light/arrow_right_disabled.png\");\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  su"
                        "bcontrol-position: right;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal:hover, QScrollBar::add-line:horizontal:on {\n"
"  border-image: url(\":/qss_icons/light/rc_light/arrow_right.png\");\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  subcontrol-position: right;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"  margin: 3px 0px 3px 0px;\n"
"  border-image: url(\":/qss_icons/light/rc_light/arrow_down_disabled.png\");\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  subcontrol-position: bottom;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical:hover, QScrollBar::add-line:vertical:on {\n"
"  border-image: url(\":/qss_icons/light/rc_light/arrow_down.png\");\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  subcontrol-position: bottom;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"  margin: 0px 3px 0px 3px;\n"
"  border-image: url(\":/qss_icons/light/rc_light/arrow_left_disabled.png\");\n"
""
                        "  height: 12px;\n"
"  width: 12px;\n"
"  subcontrol-position: left;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal:hover, QScrollBar::sub-line:horizontal:on {\n"
"  border-image: url(\":/qss_icons/light/rc_light/arrow_left.png\");\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  subcontrol-position: left;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"  margin: 3px 0px 3px 0px;\n"
"  border-image: url(\":/qss_icons/light/rc_light/arrow_up_disabled.png\");\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  subcontrol-position: top;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical:hover, QScrollBar::sub-line:vertical:on {\n"
"  border-image: url(\":/qss_icons/light/rc_light/arrow_up.png\");\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  subcontrol-position: top;\n"
"  subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:horizontal, QScrollBar::down-arrow:horizontal {\n"
"  background: none;\n"
"}\n"
"\n"
"QScrollBar:"
                        ":up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"  background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"  background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"  background: none;\n"
"}\n"
"\n"
"/* QTextEdit --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-specific-widgets\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QTextEdit {\n"
"  background-color: #FAFAFA;\n"
"  color: #19232D;\n"
"  border-radius: 4px;\n"
"  border: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QTextEdit:selected {\n"
"  background: #9FCBFF;\n"
"  color: #C0C4C8;\n"
"}\n"
"\n"
"/* QPlainTextEdit ---------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QPlainText"
                        "Edit {\n"
"  background-color: #FAFAFA;\n"
"  color: #19232D;\n"
"  border-radius: 4px;\n"
"  border: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"QPlainTextEdit:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QPlainTextEdit:selected {\n"
"  background: #9FCBFF;\n"
"  color: #C0C4C8;\n"
"}\n"
"\n"
"/* QSizeGrip --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qsizegrip\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QSizeGrip {\n"
"  background: transparent;\n"
"  width: 12px;\n"
"  height: 12px;\n"
"  image: url(\":/qss_icons/light/rc_light/window_grip.png\");\n"
"}\n"
"\n"
"/* QStackedWidget ---------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QStackedWidget {\n"
"  padding: 2px;\n"
"  border: 1px solid #C0C4C8;\n"
"  border: 1px solid #FAFAFA;\n"
"}\n"
"\n"
"/* QToolBar --------------------"
                        "-------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtoolbar\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QToolBar {\n"
"  background-color: #C0C4C8;\n"
"  border-bottom: 1px solid #FAFAFA;\n"
"  padding: 1px;\n"
"  font-weight: bold;\n"
"  spacing: 2px;\n"
"}\n"
"\n"
"QToolBar:disabled {\n"
"  /* Fixes #272 */\n"
"  background-color: #C0C4C8;\n"
"}\n"
"\n"
"QToolBar::handle:horizontal {\n"
"  width: 16px;\n"
"  image: url(\":/qss_icons/light/rc_light/toolbar_move_horizontal.png\");\n"
"}\n"
"\n"
"QToolBar::handle:vertical {\n"
"  height: 16px;\n"
"  image: url(\":/qss_icons/light/rc_light/toolbar_move_vertical.png\");\n"
"}\n"
"\n"
"QToolBar::separator:horizontal {\n"
"  width: 16px;\n"
"  image: url(\":/qss_icons/light/rc_light/toolbar_separator_horizontal.png\");\n"
"}\n"
"\n"
"QToolBar::separator:vertical {\n"
"  height: 16px;\n"
"  image: url(\":/qss_icons/light/rc_light/toolbar_separator_vertical.p"
                        "ng\");\n"
"}\n"
"\n"
"QToolButton#qt_toolbar_ext_button {\n"
"  background: #C0C4C8;\n"
"  border: 0px;\n"
"  color: #19232D;\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_right.png\");\n"
"}\n"
"\n"
"/* QAbstractSpinBox -------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QAbstractSpinBox {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  color: #19232D;\n"
"  /* This fixes 103, 111 */\n"
"  padding-top: 2px;\n"
"  /* This fixes 103, 111 */\n"
"  padding-bottom: 2px;\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  border-radius: 4px;\n"
"  /* min-width: 5px; removed to fix 109 */\n"
"}\n"
"\n"
"QAbstractSpinBox:up-button {\n"
"  background-color: transparent #FAFAFA;\n"
"  subcontrol-origin: border;\n"
"  subcontrol-position: top right;\n"
"  border-left: 1px solid #C0C4C8;\n"
"  border-bottom: 1px solid #C0C4C8;\n"
"  border-top-left-radius: 0;\n"
"  border-bottom-left-radius: "
                        "0;\n"
"  margin: 1px;\n"
"  width: 12px;\n"
"  margin-bottom: -1px;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow, QAbstractSpinBox::up-arrow:disabled, QAbstractSpinBox::up-arrow:off {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_up_disabled.png\");\n"
"  height: 8px;\n"
"  width: 8px;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow:hover {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_up.png\");\n"
"}\n"
"\n"
"QAbstractSpinBox:down-button {\n"
"  background-color: transparent #FAFAFA;\n"
"  subcontrol-origin: border;\n"
"  subcontrol-position: bottom right;\n"
"  border-left: 1px solid #C0C4C8;\n"
"  border-top: 1px solid #C0C4C8;\n"
"  border-top-left-radius: 0;\n"
"  border-bottom-left-radius: 0;\n"
"  margin: 1px;\n"
"  width: 12px;\n"
"  margin-top: -1px;\n"
"}\n"
"\n"
"QAbstractSpinBox::down-arrow, QAbstractSpinBox::down-arrow:disabled, QAbstractSpinBox::down-arrow:off {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down_disabled.png\");\n"
"  height: 8px;\n"
"  width: 8px;\n"
"}\n"
"\n"
"QAbstr"
                        "actSpinBox::down-arrow:hover {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down.png\");\n"
"}\n"
"\n"
"QAbstractSpinBox:hover {\n"
"  border: 1px solid #9FCBFF;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QAbstractSpinBox:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QAbstractSpinBox:selected {\n"
"  background: #9FCBFF;\n"
"  color: #C0C4C8;\n"
"}\n"
"\n"
"/* ------------------------------------------------------------------------ */\n"
"/* DISPLAYS --------------------------------------------------------------- */\n"
"/* ------------------------------------------------------------------------ */\n"
"/* QLabel -----------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qframe\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QLabel {\n"
"  background-color: #FAFAFA;\n"
"  border: 0px solid #C0C4C8;\n"
"  padding: 2px;\n"
"  margin: 0px;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QLabel:dis"
                        "abled {\n"
"  background-color: #FAFAFA;\n"
"  border: 0px solid #C0C4C8;\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"/* QTextBrowser -----------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qabstractscrollarea\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QTextBrowser {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  color: #19232D;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QTextBrowser:disabled {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  color: #9DA9B5;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QTextBrowser:hover, QTextBrowser:!hover, QTextBrowser:selected, QTextBrowser:pressed {\n"
"  border: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"/* QGraphicsView ----------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QGraphicsView {\n"
"  background-color: #FAFAFA;\n"
"  bo"
                        "rder: 1px solid #C0C4C8;\n"
"  color: #19232D;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QGraphicsView:disabled {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  color: #9DA9B5;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QGraphicsView:hover, QGraphicsView:!hover, QGraphicsView:selected, QGraphicsView:pressed {\n"
"  border: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"/* QCalendarWidget --------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QCalendarWidget {\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QCalendarWidget:disabled {\n"
"  background-color: #FAFAFA;\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"/* QLCDNumber -------------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QLCDNumber {\n"
"  background-color: #FAFAFA;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QLCDNumber:disabled {\n"
"  backgrou"
                        "nd-color: #FAFAFA;\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"/* QProgressBar -----------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qprogressbar\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QProgressBar {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  color: #19232D;\n"
"  border-radius: 4px;\n"
"  text-align: center;\n"
"}\n"
"\n"
"QProgressBar:disabled {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  color: #9DA9B5;\n"
"  border-radius: 4px;\n"
"  text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"  background-color: #9FCBFF;\n"
"  color: #FAFAFA;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QProgressBar::chunk:disabled {\n"
"  background-color: #DAEDFF;\n"
"  color: #9DA9B5;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"/* ------------------------------------------------------------------------ */\n"
"/* BUTTONS -------------------------------"
                        "--------------------------------- */\n"
"/* ------------------------------------------------------------------------ */\n"
"/* QPushButton ------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qpushbutton\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QPushButton {\n"
"  background-color: #C0C4C8;\n"
"  color: #19232D;\n"
"  border-radius: 4px;\n"
"  padding: 2px;\n"
"  outline: none;\n"
"  border: none;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"  background-color: #C0C4C8;\n"
"  color: #9DA9B5;\n"
"  border-radius: 4px;\n"
"  padding: 2px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  background-color: #73C7FF;\n"
"  border-radius: 4px;\n"
"  padding: 2px;\n"
"  outline: none;\n"
"}\n"
"\n"
"QPushButton:checked:disabled {\n"
"  background-color: #73C7FF;\n"
"  color: #9DA9B5;\n"
"  border-radius: 4px;\n"
"  padding: 2px;\n"
"  outline: none;\n"
"}\n"
"\n"
"QPushButton:checked:hover {\n"
"  bac"
                        "kground: #37AEFE;\n"
"}\n"
"\n"
"QPushButton:checked:selected {\n"
"  background: #ACB1B6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: #B4B8BC;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"  background-color: #ACB1B6;\n"
"}\n"
"\n"
"QPushButton:selected {\n"
"  background: #ACB1B6;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QPushButton::menu-indicator {\n"
"  subcontrol-origin: padding;\n"
"  subcontrol-position: bottom right;\n"
"  bottom: 4px;\n"
"}\n"
"\n"
"QDialogButtonBox QPushButton {\n"
"  /* Issue #194 #248 - Special case of QPushButton inside dialogs, for better UI */\n"
"  min-width: 80px;\n"
"  min-height: 25px;\n"
"}\n"
"\n"
"/* QToolButton ------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtoolbutton\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QToolButton {\n"
"  background-color: #C0C4C8;\n"
"  color: #19232D;\n"
"  border-radius: 4px;\n"
"  pa"
                        "dding: 2px;\n"
"  outline: none;\n"
"  border: none;\n"
"  /* The subcontrols below are used only in the DelayedPopup mode */\n"
"  /* The subcontrols below are used only in the MenuButtonPopup mode */\n"
"  /* The subcontrol below is used only in the InstantPopup or DelayedPopup mode */\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"  background-color: #C0C4C8;\n"
"  color: #9DA9B5;\n"
"  border-radius: 4px;\n"
"  padding: 2px;\n"
"}\n"
"\n"
"QToolButton:checked {\n"
"  background-color: #ACB1B6;\n"
"  border-radius: 4px;\n"
"  padding: 2px;\n"
"  outline: none;\n"
"}\n"
"\n"
"QToolButton:checked:disabled {\n"
"  background-color: #ACB1B6;\n"
"  color: #9DA9B5;\n"
"  border-radius: 4px;\n"
"  padding: 2px;\n"
"  outline: none;\n"
"}\n"
"\n"
"QToolButton:checked:hover {\n"
"  background-color: #B4B8BC;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QToolButton:checked:pressed {\n"
"  background-color: #ACB1B6;\n"
"}\n"
"\n"
"QToolButton:checked:selected {\n"
"  background: #ACB1B6;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QToolB"
                        "utton:hover {\n"
"  background-color: #B4B8BC;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"  background-color: #ACB1B6;\n"
"}\n"
"\n"
"QToolButton:selected {\n"
"  background: #ACB1B6;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"0\"] {\n"
"  /* Only for DelayedPopup */\n"
"  padding-right: 2px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"] {\n"
"  /* Only for MenuButtonPopup */\n"
"  padding-right: 20px;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"]::menu-button {\n"
"  border: none;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"1\"]::menu-button:hover {\n"
"  border: none;\n"
"  border-left: 1px solid #C0C4C8;\n"
"  border-radius: 0;\n"
"}\n"
"\n"
"QToolButton[popupMode=\"2\"] {\n"
"  /* Only for InstantPopup */\n"
"  padding-right: 2px;\n"
"}\n"
"\n"
"QToolButton::menu-button {\n"
"  padding: 2px;\n"
"  border-radius: 4px;\n"
"  width: 12px;\n"
"  border: none;\n"
"  outline: none;\n"
"}\n"
"\n"
"QToolButton::menu-button:hover {\n"
"  border: 1px solid #9FCBFF;\n"
"}\n"
"\n"
"QToolBu"
                        "tton::menu-button:checked:hover {\n"
"  border: 1px solid #9FCBFF;\n"
"}\n"
"\n"
"QToolButton::menu-indicator {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down.png\");\n"
"  height: 8px;\n"
"  width: 8px;\n"
"  top: 0;\n"
"  /* Exclude a shift for better image */\n"
"  left: -2px;\n"
"  /* Shift it a bit */\n"
"}\n"
"\n"
"QToolButton::menu-arrow {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down.png\");\n"
"  height: 8px;\n"
"  width: 8px;\n"
"}\n"
"\n"
"QToolButton::menu-arrow:hover {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down_focus.png\");\n"
"}\n"
"\n"
"/* QCommandLinkButton -----------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QCommandLinkButton {\n"
"  background-color: transparent;\n"
"  border: 1px solid #C0C4C8;\n"
"  color: #19232D;\n"
"  border-radius: 4px;\n"
"  padding: 0px;\n"
"  margin: 0px;\n"
"}\n"
"\n"
"QCommandLinkButton:disabled {\n"
"  background-color: transparent;\n"
""
                        "  color: #9DA9B5;\n"
"}\n"
"\n"
"/* ------------------------------------------------------------------------ */\n"
"/* INPUTS - NO FIELDS ----------------------------------------------------- */\n"
"/* ------------------------------------------------------------------------ */\n"
"/* QComboBox --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qcombobox\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QComboBox {\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"  selection-background-color: #9FCBFF;\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  /* padding-right = 36; 4 + 16*2 See scrollbar size */\n"
"  /* changed to 4px to fix #239 */\n"
"  /* Fixes #103, #111 */\n"
"  min-height: 1.5em;\n"
"  /* padding-top: 2px;     removed to fix #132 */\n"
"  /* padding-bottom: 2px;  removed to fix #132 */\n"
"  /* min-width: 75px;      removed to fix #109 */\n"
"  /* Needed "
                        "to remove indicator - fix #132 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 0;\n"
"  background-color: #FAFAFA;\n"
"  selection-background-color: #9FCBFF;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView:hover {\n"
"  background-color: #FAFAFA;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView:selected {\n"
"  background: #9FCBFF;\n"
"  color: #C0C4C8;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView:alternate {\n"
"  background: #FAFAFA;\n"
"}\n"
"\n"
"QComboBox:disabled {\n"
"  background-color: #FAFAFA;\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"  border: 1px solid #9FCBFF;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"  selection-background-color: #9FCBFF;\n"
"}\n"
"\n"
"QComboBox::indicator {\n"
"  border: none;\n"
"  border-radius: 0;\n"
"  background-color: transparent;\n"
"  selection-background-color: transparent;\n"
"  color: transparent;\n"
"  selection-color: transparent"
                        ";\n"
"  /* Needed to remove indicator - fix #132 */\n"
"}\n"
"\n"
"QComboBox::indicator:alternate {\n"
"  background: #FAFAFA;\n"
"}\n"
"\n"
"QComboBox::item {\n"
"  /* Remove to fix #282, #285 and MR #288*/\n"
"  /*&:checked {\n"
"            font-weight: bold;\n"
"        }\n"
"\n"
"        &:selected {\n"
"            border: 0px solid transparent;\n"
"        }\n"
"        */\n"
"}\n"
"\n"
"QComboBox::item:alternate {\n"
"  background: #FAFAFA;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"  subcontrol-origin: padding;\n"
"  subcontrol-position: top right;\n"
"  width: 12px;\n"
"  border-left: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down_disabled.png\");\n"
"  height: 8px;\n"
"  width: 8px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on, QComboBox::down-arrow:hover, QComboBox::down-arrow:focus {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down.png\");\n"
"}\n"
"\n"
"/* QSlider ----------------------------------------------------------------"
                        "\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qslider\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QSlider:disabled {\n"
"  background: #FAFAFA;\n"
"}\n"
"\n"
"QSlider:focus {\n"
"  border: none;\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"  background: #C0C4C8;\n"
"  border: 1px solid #C0C4C8;\n"
"  height: 4px;\n"
"  margin: 0px;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"  background: #C0C4C8;\n"
"  border: 1px solid #C0C4C8;\n"
"  width: 4px;\n"
"  margin: 0px;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:vertical {\n"
"  background: #9FCBFF;\n"
"  border: 1px solid #C0C4C8;\n"
"  width: 4px;\n"
"  margin: 0px;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:vertical :disabled {\n"
"  background: #DAEDFF;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"  background: #9FCBFF;\n"
"  border: 1px solid #C0C4C8;\n"
"  height: 4px;\n"
"  margin: 0px;\n"
"  border-radius: 4px;\n"
"}\n"
""
                        "\n"
"QSlider::sub-page:horizontal:disabled {\n"
"  background: #DAEDFF;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"  background: #788D9C;\n"
"  border: 1px solid #C0C4C8;\n"
"  width: 8px;\n"
"  height: 8px;\n"
"  margin: -8px 0px;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"  background: #9FCBFF;\n"
"  border: 1px solid #9FCBFF;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"  background: #788D9C;\n"
"  border: 1px solid #C0C4C8;\n"
"  width: 8px;\n"
"  height: 8px;\n"
"  margin: 0 -8px;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:vertical:hover {\n"
"  background: #9FCBFF;\n"
"  border: 1px solid #9FCBFF;\n"
"}\n"
"\n"
"QSlider::handle:vertical:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"/* QLineEdit --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qlineedit\n"
"\n"
"--------------"
                        "------------------------------------------------------------- */\n"
"QLineEdit {\n"
"  background-color: #FAFAFA;\n"
"  padding-top: 2px;\n"
"  /* This QLineEdit fix  103, 111 */\n"
"  padding-bottom: 2px;\n"
"  /* This QLineEdit fix  103, 111 */\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  border-style: solid;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"  background-color: #FAFAFA;\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"  border: 1px solid #9FCBFF;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QLineEdit:selected {\n"
"  background-color: #9FCBFF;\n"
"  color: #C0C4C8;\n"
"}\n"
"\n"
"/* QTabWiget --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtabwidget-and-qtabbar\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QTabWidg"
                        "et {\n"
"  padding: 2px;\n"
"  selection-background-color: #C0C4C8;\n"
"}\n"
"\n"
"QTabWidget QWidget {\n"
"  /* Fixes #189 */\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"  margin: 0px;\n"
"  /* Fixes double border inside pane with pyqt5 */\n"
"  padding: 0px;\n"
"}\n"
"\n"
"QTabWidget::pane:selected {\n"
"  background-color: #C0C4C8;\n"
"  border: 1px solid #9FCBFF;\n"
"}\n"
"\n"
"/* QTabBar ----------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtabwidget-and-qtabbar\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QTabBar, QDockWidget QTabBar {\n"
"  qproperty-drawBase: 0;\n"
"  border-radius: 4px;\n"
"  margin: 0px;\n"
"  padding: 2px;\n"
"  border: 0;\n"
"  /* left: 5px; move to the right by 5px - removed for fix */\n"
"}\n"
"\n"
"QTabBar::close-button, QDockWidget QTabBar::close-button {\n"
"  border: 0;\n"
""
                        "  margin: 0;\n"
"  padding: 4px;\n"
"  image: url(\":/qss_icons/light/rc_light/window_close.png\");\n"
"}\n"
"\n"
"QTabBar::close-button:hover, QDockWidget QTabBar::close-button:hover {\n"
"  image: url(\":/qss_icons/light/rc_light/window_close_focus.png\");\n"
"}\n"
"\n"
"QTabBar::close-button:pressed, QDockWidget QTabBar::close-button:pressed {\n"
"  image: url(\":/qss_icons/light/rc_light/window_close_pressed.png\");\n"
"}\n"
"\n"
"QTabBar::tab, QDockWidget QTabBar::tab {\n"
"  /* !selected and disabled ----------------------------------------- */\n"
"  /* selected ------------------------------------------------------- */\n"
"}\n"
"\n"
"QTabBar::tab:top:selected:disabled, QDockWidget QTabBar::tab:top:selected:disabled {\n"
"  border-bottom: 3px solid #DAEDFF;\n"
"  color: #9DA9B5;\n"
"  background-color: #C0C4C8;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected:disabled, QDockWidget QTabBar::tab:bottom:selected:disabled {\n"
"  border-top: 3px solid #DAEDFF;\n"
"  color: #9DA9B5;\n"
"  background-color: #C0C4C8"
                        ";\n"
"}\n"
"\n"
"QTabBar::tab:left:selected:disabled, QDockWidget QTabBar::tab:left:selected:disabled {\n"
"  border-right: 3px solid #DAEDFF;\n"
"  color: #9DA9B5;\n"
"  background-color: #C0C4C8;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected:disabled, QDockWidget QTabBar::tab:right:selected:disabled {\n"
"  border-left: 3px solid #DAEDFF;\n"
"  color: #9DA9B5;\n"
"  background-color: #C0C4C8;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected:disabled, QDockWidget QTabBar::tab:top:!selected:disabled {\n"
"  border-bottom: 3px solid #FAFAFA;\n"
"  color: #9DA9B5;\n"
"  background-color: #FAFAFA;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected:disabled, QDockWidget QTabBar::tab:bottom:!selected:disabled {\n"
"  border-top: 3px solid #FAFAFA;\n"
"  color: #9DA9B5;\n"
"  background-color: #FAFAFA;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected:disabled, QDockWidget QTabBar::tab:left:!selected:disabled {\n"
"  border-right: 3px solid #FAFAFA;\n"
"  color: #9DA9B5;\n"
"  background-color: #FAFAFA;\n"
"}\n"
"\n"
"QTabBar::tab:right:!"
                        "selected:disabled, QDockWidget QTabBar::tab:right:!selected:disabled {\n"
"  border-left: 3px solid #FAFAFA;\n"
"  color: #9DA9B5;\n"
"  background-color: #FAFAFA;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected, QDockWidget QTabBar::tab:top:!selected {\n"
"  border-bottom: 2px solid #FAFAFA;\n"
"  margin-top: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected, QDockWidget QTabBar::tab:bottom:!selected {\n"
"  border-top: 2px solid #FAFAFA;\n"
"  margin-bottom: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected, QDockWidget QTabBar::tab:left:!selected {\n"
"  border-left: 2px solid #FAFAFA;\n"
"  margin-right: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected, QDockWidget QTabBar::tab:right:!selected {\n"
"  border-right: 2px solid #FAFAFA;\n"
"  margin-left: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:top, QDockWidget QTabBar::tab:top {\n"
"  background-color: #C0C4C8;\n"
"  margin-left: 2px;\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  padding-top: 2px;\n"
"  padding-bottom: 2px;\n"
"  min-width: 5px;\n"
"  border-bot"
                        "tom: 3px solid #C0C4C8;\n"
"  border-top-left-radius: 4px;\n"
"  border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selected, QDockWidget QTabBar::tab:top:selected {\n"
"  background-color: #B4B8BC;\n"
"  border-bottom: 3px solid #37AEFE;\n"
"  border-top-left-radius: 4px;\n"
"  border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected:hover, QDockWidget QTabBar::tab:top:!selected:hover {\n"
"  border: 1px solid #73C7FF;\n"
"  border-bottom: 3px solid #73C7FF;\n"
"  /* Fixes spyder-ide/spyder#9766 and #243 */\n"
"  padding-left: 3px;\n"
"  padding-right: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom, QDockWidget QTabBar::tab:bottom {\n"
"  border-top: 3px solid #C0C4C8;\n"
"  background-color: #C0C4C8;\n"
"  margin-left: 2px;\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  padding-top: 2px;\n"
"  padding-bottom: 2px;\n"
"  border-bottom-left-radius: 4px;\n"
"  border-bottom-right-radius: 4px;\n"
"  min-width: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected, QDockWidget QTabBar::tab"
                        ":bottom:selected {\n"
"  background-color: #B4B8BC;\n"
"  border-top: 3px solid #37AEFE;\n"
"  border-bottom-left-radius: 4px;\n"
"  border-bottom-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected:hover, QDockWidget QTabBar::tab:bottom:!selected:hover {\n"
"  border: 1px solid #73C7FF;\n"
"  border-top: 3px solid #73C7FF;\n"
"  /* Fixes spyder-ide/spyder#9766 and #243 */\n"
"  padding-left: 3px;\n"
"  padding-right: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:left, QDockWidget QTabBar::tab:left {\n"
"  background-color: #C0C4C8;\n"
"  margin-top: 2px;\n"
"  padding-left: 2px;\n"
"  padding-right: 2px;\n"
"  padding-top: 4px;\n"
"  padding-bottom: 4px;\n"
"  border-top-left-radius: 4px;\n"
"  border-bottom-left-radius: 4px;\n"
"  min-height: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected, QDockWidget QTabBar::tab:left:selected {\n"
"  background-color: #B4B8BC;\n"
"  border-right: 3px solid #37AEFE;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected:hover, QDockWidget QTabBar::tab:left:!selected:hover {\n"
"  border"
                        ": 1px solid #73C7FF;\n"
"  border-right: 3px solid #73C7FF;\n"
"  /* Fixes different behavior #271 */\n"
"  margin-right: 0px;\n"
"  padding-right: -1px;\n"
"}\n"
"\n"
"QTabBar::tab:right, QDockWidget QTabBar::tab:right {\n"
"  background-color: #C0C4C8;\n"
"  margin-top: 2px;\n"
"  padding-left: 2px;\n"
"  padding-right: 2px;\n"
"  padding-top: 4px;\n"
"  padding-bottom: 4px;\n"
"  border-top-right-radius: 4px;\n"
"  border-bottom-right-radius: 4px;\n"
"  min-height: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected, QDockWidget QTabBar::tab:right:selected {\n"
"  background-color: #B4B8BC;\n"
"  border-left: 3px solid #37AEFE;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected:hover, QDockWidget QTabBar::tab:right:!selected:hover {\n"
"  border: 1px solid #73C7FF;\n"
"  border-left: 3px solid #73C7FF;\n"
"  /* Fixes different behavior #271 */\n"
"  margin-left: 0px;\n"
"  padding-left: 0px;\n"
"}\n"
"\n"
"QTabBar QToolButton, QDockWidget QTabBar QToolButton {\n"
"  /* Fixes #136 */\n"
"  background-color: #C0C4C8;\n"
""
                        "  height: 12px;\n"
"  width: 12px;\n"
"}\n"
"\n"
"QTabBar QToolButton:pressed, QDockWidget QTabBar QToolButton:pressed {\n"
"  background-color: #C0C4C8;\n"
"}\n"
"\n"
"QTabBar QToolButton:pressed:hover, QDockWidget QTabBar QToolButton:pressed:hover {\n"
"  border: 1px solid #9FCBFF;\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:enabled, QDockWidget QTabBar QToolButton::left-arrow:enabled {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_left.png\");\n"
"}\n"
"\n"
"QTabBar QToolButton::left-arrow:disabled, QDockWidget QTabBar QToolButton::left-arrow:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_left_disabled.png\");\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:enabled, QDockWidget QTabBar QToolButton::right-arrow:enabled {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_right.png\");\n"
"}\n"
"\n"
"QTabBar QToolButton::right-arrow:disabled, QDockWidget QTabBar QToolButton::right-arrow:disabled {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_right_disabled.png\");\n"
"}\n"
"\n"
""
                        "/* QDockWiget -------------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QDockWidget {\n"
"  outline: 1px solid #C0C4C8;\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"  titlebar-close-icon: url(\":/qss_icons/light/rc_light/transparent.png\");\n"
"  titlebar-normal-icon: url(\":/qss_icons/light/rc_light/transparent.png\");\n"
"}\n"
"\n"
"QDockWidget::title {\n"
"  /* Better size for title bar */\n"
"  padding: 3px;\n"
"  spacing: 4px;\n"
"  border: none;\n"
"  background-color: #C0C4C8;\n"
"}\n"
"\n"
"QDockWidget::close-button {\n"
"  icon-size: 12px;\n"
"  border: none;\n"
"  background: transparent;\n"
"  background-image: transparent;\n"
"  border: 0;\n"
"  margin: 0;\n"
"  padding: 0;\n"
"  image: url(\":/qss_icons/light/rc_light/window_close.png\");\n"
"}\n"
"\n"
"QDockWidget::close-button:hover {\n"
"  image: url(\":/qss_icons/light/rc_light/window_close_focus.pn"
                        "g\");\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed {\n"
"  image: url(\":/qss_icons/light/rc_light/window_close_pressed.png\");\n"
"}\n"
"\n"
"QDockWidget::float-button {\n"
"  icon-size: 12px;\n"
"  border: none;\n"
"  background: transparent;\n"
"  background-image: transparent;\n"
"  border: 0;\n"
"  margin: 0;\n"
"  padding: 0;\n"
"  image: url(\":/qss_icons/light/rc_light/window_undock.png\");\n"
"}\n"
"\n"
"QDockWidget::float-button:hover {\n"
"  image: url(\":/qss_icons/light/rc_light/window_undock_focus.png\");\n"
"}\n"
"\n"
"QDockWidget::float-button:pressed {\n"
"  image: url(\":/qss_icons/light/rc_light/window_undock_pressed.png\");\n"
"}\n"
"\n"
"/* QTreeView QListView QTableView -----------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtreeview\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qlistview\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtableview\n"
"\n"
"-----------------------------------------"
                        "---------------------------------- */\n"
"QTreeView:branch:selected, QTreeView:branch:hover {\n"
"  background: url(\":/qss_icons/light/rc_light/transparent.png\");\n"
"}\n"
"\n"
"QTreeView:branch:has-siblings:!adjoins-item {\n"
"  border-image: url(\":/qss_icons/light/rc_light/branch_line.png\") 0;\n"
"}\n"
"\n"
"QTreeView:branch:has-siblings:adjoins-item {\n"
"  border-image: url(\":/qss_icons/light/rc_light/branch_more.png\") 0;\n"
"}\n"
"\n"
"QTreeView:branch:!has-children:!has-siblings:adjoins-item {\n"
"  border-image: url(\":/qss_icons/light/rc_light/branch_end.png\") 0;\n"
"}\n"
"\n"
"QTreeView:branch:has-children:!has-siblings:closed, QTreeView:branch:closed:has-children:has-siblings {\n"
"  border-image: none;\n"
"  image: url(\":/qss_icons/light/rc_light/branch_closed.png\");\n"
"}\n"
"\n"
"QTreeView:branch:open:has-children:!has-siblings, QTreeView:branch:open:has-children:has-siblings {\n"
"  border-image: none;\n"
"  image: url(\":/qss_icons/light/rc_light/branch_open.png\");\n"
"}\n"
"\n"
"QTree"
                        "View:branch:has-children:!has-siblings:closed:hover, QTreeView:branch:closed:has-children:has-siblings:hover {\n"
"  image: url(\":/qss_icons/light/rc_light/branch_closed_focus.png\");\n"
"}\n"
"\n"
"QTreeView:branch:open:has-children:!has-siblings:hover, QTreeView:branch:open:has-children:has-siblings:hover {\n"
"  image: url(\":/qss_icons/light/rc_light/branch_open_focus.png\");\n"
"}\n"
"\n"
"QTreeView::indicator:checked,\n"
"QListView::indicator:checked,\n"
"QTableView::indicator:checked,\n"
"QColumnView::indicator:checked {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked.png\");\n"
"}\n"
"\n"
"QTreeView::indicator:checked:hover, QTreeView::indicator:checked:focus, QTreeView::indicator:checked:pressed,\n"
"QListView::indicator:checked:hover,\n"
"QListView::indicator:checked:focus,\n"
"QListView::indicator:checked:pressed,\n"
"QTableView::indicator:checked:hover,\n"
"QTableView::indicator:checked:focus,\n"
"QTableView::indicator:checked:pressed,\n"
"QColumnView::indicator:checked:hover,\n"
"Q"
                        "ColumnView::indicator:checked:focus,\n"
"QColumnView::indicator:checked:pressed {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_checked_focus.png\");\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked,\n"
"QListView::indicator:unchecked,\n"
"QTableView::indicator:unchecked,\n"
"QColumnView::indicator:unchecked {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked.png\");\n"
"}\n"
"\n"
"QTreeView::indicator:unchecked:hover, QTreeView::indicator:unchecked:focus, QTreeView::indicator:unchecked:pressed,\n"
"QListView::indicator:unchecked:hover,\n"
"QListView::indicator:unchecked:focus,\n"
"QListView::indicator:unchecked:pressed,\n"
"QTableView::indicator:unchecked:hover,\n"
"QTableView::indicator:unchecked:focus,\n"
"QTableView::indicator:unchecked:pressed,\n"
"QColumnView::indicator:unchecked:hover,\n"
"QColumnView::indicator:unchecked:focus,\n"
"QColumnView::indicator:unchecked:pressed {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_unchecked_focus.png\");\n"
"}\n"
"\n"
"QTreeView::indi"
                        "cator:indeterminate,\n"
"QListView::indicator:indeterminate,\n"
"QTableView::indicator:indeterminate,\n"
"QColumnView::indicator:indeterminate {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_indeterminate.png\");\n"
"}\n"
"\n"
"QTreeView::indicator:indeterminate:hover, QTreeView::indicator:indeterminate:focus, QTreeView::indicator:indeterminate:pressed,\n"
"QListView::indicator:indeterminate:hover,\n"
"QListView::indicator:indeterminate:focus,\n"
"QListView::indicator:indeterminate:pressed,\n"
"QTableView::indicator:indeterminate:hover,\n"
"QTableView::indicator:indeterminate:focus,\n"
"QTableView::indicator:indeterminate:pressed,\n"
"QColumnView::indicator:indeterminate:hover,\n"
"QColumnView::indicator:indeterminate:focus,\n"
"QColumnView::indicator:indeterminate:pressed {\n"
"  image: url(\":/qss_icons/light/rc_light/checkbox_indeterminate_focus.png\");\n"
"}\n"
"\n"
"QTreeView,\n"
"QListView,\n"
"QTableView,\n"
"QColumnView {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px solid #C0C4C8;\n"
"  "
                        "color: #19232D;\n"
"  gridline-color: #C0C4C8;\n"
"  border-radius: 4px;\n"
"}\n"
"\n"
"QTreeView:disabled,\n"
"QListView:disabled,\n"
"QTableView:disabled,\n"
"QColumnView:disabled {\n"
"  background-color: #FAFAFA;\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"QTreeView:selected,\n"
"QListView:selected,\n"
"QTableView:selected,\n"
"QColumnView:selected {\n"
"  background-color: #9FCBFF;\n"
"  color: #C0C4C8;\n"
"}\n"
"\n"
"QTreeView:focus,\n"
"QListView:focus,\n"
"QTableView:focus,\n"
"QColumnView:focus {\n"
"  border: 1px solid #73C7FF;\n"
"}\n"
"\n"
"QTreeView::item:pressed,\n"
"QListView::item:pressed,\n"
"QTableView::item:pressed,\n"
"QColumnView::item:pressed {\n"
"  background-color: #9FCBFF;\n"
"}\n"
"\n"
"QTreeView::item:selected:active,\n"
"QListView::item:selected:active,\n"
"QTableView::item:selected:active,\n"
"QColumnView::item:selected:active {\n"
"  background-color: #9FCBFF;\n"
"}\n"
"\n"
"QTreeView::item:selected:!active,\n"
"QListView::item:selected:!active,\n"
"QTableView::item:selected:!active,\n"
""
                        "QColumnView::item:selected:!active {\n"
"  color: #19232D;\n"
"  background-color: #D2D5D8;\n"
"}\n"
"\n"
"QTreeView::item:!selected:hover,\n"
"QListView::item:!selected:hover,\n"
"QTableView::item:!selected:hover,\n"
"QColumnView::item:!selected:hover {\n"
"  outline: 0;\n"
"  color: #19232D;\n"
"  background-color: #D2D5D8;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"  background-color: #FAFAFA;\n"
"  border: 1px transparent #C0C4C8;\n"
"  border-radius: 0px;\n"
"}\n"
"\n"
"/* QHeaderView ------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qheaderview\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QHeaderView {\n"
"  background-color: #C0C4C8;\n"
"  border: 0px transparent #C0C4C8;\n"
"  padding: 0;\n"
"  margin: 0;\n"
"  border-radius: 0;\n"
"}\n"
"\n"
"QHeaderView:disabled {\n"
"  background-color: #C0C4C8;\n"
"  border: 1px transparent #C0C4C8;\n"
"}\n"
"\n"
"QHeaderView::section"
                        " {\n"
"  background-color: #C0C4C8;\n"
"  color: #19232D;\n"
"  border-radius: 0;\n"
"  text-align: left;\n"
"  font-size: 13px;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal {\n"
"  padding-top: 0;\n"
"  padding-bottom: 0;\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  border-left: 1px solid #FAFAFA;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal::first, QHeaderView::section::horizontal::only-one {\n"
"  border-left: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal:disabled {\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"QHeaderView::section::vertical {\n"
"  padding-top: 0;\n"
"  padding-bottom: 0;\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  border-top: 1px solid #FAFAFA;\n"
"}\n"
"\n"
"QHeaderView::section::vertical::first, QHeaderView::section::vertical::only-one {\n"
"  border-top: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"QHeaderView::section::vertical:disabled {\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"QHeaderView::down-arrow {\n"
"  /* Those settings (border/width/height/backgrou"
                        "nd-color) solve bug */\n"
"  /* transparent arrow background and size */\n"
"  background-color: #C0C4C8;\n"
"  border: none;\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  padding-left: 2px;\n"
"  padding-right: 2px;\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down.png\");\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"  background-color: #C0C4C8;\n"
"  border: none;\n"
"  height: 12px;\n"
"  width: 12px;\n"
"  padding-left: 2px;\n"
"  padding-right: 2px;\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_up.png\");\n"
"}\n"
"\n"
"/* QToolBox --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qtoolbox\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QToolBox {\n"
"  padding: 0px;\n"
"  border: 0px;\n"
"  border: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"QToolBox:selected {\n"
"  padding: 0px;\n"
"  border: 2px solid #9FCBFF;\n"
"}\n"
"\n"
"QToolBox::tab {\n"
"  background-color: #FAFAFA;\n"
""
                        "  border: 1px solid #C0C4C8;\n"
"  color: #19232D;\n"
"  border-top-left-radius: 4px;\n"
"  border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QToolBox::tab:disabled {\n"
"  color: #9DA9B5;\n"
"}\n"
"\n"
"QToolBox::tab:selected {\n"
"  background-color: #ACB1B6;\n"
"  border-bottom: 2px solid #9FCBFF;\n"
"}\n"
"\n"
"QToolBox::tab:selected:disabled {\n"
"  background-color: #C0C4C8;\n"
"  border-bottom: 2px solid #DAEDFF;\n"
"}\n"
"\n"
"QToolBox::tab:!selected {\n"
"  background-color: #C0C4C8;\n"
"  border-bottom: 2px solid #C0C4C8;\n"
"}\n"
"\n"
"QToolBox::tab:!selected:disabled {\n"
"  background-color: #FAFAFA;\n"
"}\n"
"\n"
"QToolBox::tab:hover {\n"
"  border-color: #73C7FF;\n"
"  border-bottom: 2px solid #73C7FF;\n"
"}\n"
"\n"
"QToolBox QScrollArea {\n"
"  padding: 0px;\n"
"  border: 0px;\n"
"  background-color: #FAFAFA;\n"
"}\n"
"\n"
"/* QFrame -----------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qframe\n"
"https://doc.qt.io/qt-5"
                        "/qframe.html#-prop\n"
"https://doc.qt.io/qt-5/qframe.html#details\n"
"https://stackoverflow.com/questions/14581498/qt-stylesheet-for-hline-vline-color\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"/* (dot) .QFrame  fix #141, #126, #123 */\n"
".QFrame {\n"
"  border-radius: 4px;\n"
"  border: 1px solid #C0C4C8;\n"
"  /* No frame */\n"
"  /* HLine */\n"
"  /* HLine */\n"
"}\n"
"\n"
".QFrame[frameShape=\"0\"] {\n"
"  border-radius: 4px;\n"
"  border: 1px transparent #C0C4C8;\n"
"}\n"
"\n"
".QFrame[frameShape=\"4\"] {\n"
"  max-height: 2px;\n"
"  border: none;\n"
"  background-color: #C0C4C8;\n"
"}\n"
"\n"
".QFrame[frameShape=\"5\"] {\n"
"  max-width: 2px;\n"
"  border: none;\n"
"  background-color: #C0C4C8;\n"
"}\n"
"\n"
"/* QSplitter --------------------------------------------------------------\n"
"\n"
"https://doc.qt.io/qt-5/stylesheet-examples.html#customizing-qsplitter\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QSp"
                        "litter {\n"
"  background-color: #C0C4C8;\n"
"  spacing: 0px;\n"
"  padding: 0px;\n"
"  margin: 0px;\n"
"}\n"
"\n"
"QSplitter::handle {\n"
"  background-color: #C0C4C8;\n"
"  border: 0px solid #FAFAFA;\n"
"  spacing: 0px;\n"
"  padding: 1px;\n"
"  margin: 0px;\n"
"}\n"
"\n"
"QSplitter::handle:hover {\n"
"  background-color: #788D9C;\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"  width: 5px;\n"
"  image: url(\":/qss_icons/light/rc_light/line_vertical.png\");\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"  height: 5px;\n"
"  image: url(\":/qss_icons/light/rc_light/line_horizontal.png\");\n"
"}\n"
"\n"
"/* QDateEdit, QDateTimeEdit -----------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QDateEdit, QDateTimeEdit {\n"
"  selection-background-color: #9FCBFF;\n"
"  border-style: solid;\n"
"  border: 1px solid #C0C4C8;\n"
"  border-radius: 4px;\n"
"  /* This fixes 103, 111 */\n"
"  padding-top: 2px;\n"
"  /* This fixes 103, 111 *"
                        "/\n"
"  padding-bottom: 2px;\n"
"  padding-left: 4px;\n"
"  padding-right: 4px;\n"
"  min-width: 10px;\n"
"}\n"
"\n"
"QDateEdit:on, QDateTimeEdit:on {\n"
"  selection-background-color: #9FCBFF;\n"
"}\n"
"\n"
"QDateEdit::drop-down, QDateTimeEdit::drop-down {\n"
"  subcontrol-origin: padding;\n"
"  subcontrol-position: top right;\n"
"  width: 12px;\n"
"  border-left: 1px solid #C0C4C8;\n"
"}\n"
"\n"
"QDateEdit::down-arrow, QDateTimeEdit::down-arrow {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down_disabled.png\");\n"
"  height: 8px;\n"
"  width: 8px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow:on, QDateEdit::down-arrow:hover, QDateEdit::down-arrow:focus, QDateTimeEdit::down-arrow:on, QDateTimeEdit::down-arrow:hover, QDateTimeEdit::down-arrow:focus {\n"
"  image: url(\":/qss_icons/light/rc_light/arrow_down.png\");\n"
"}\n"
"\n"
"QDateEdit QAbstractItemView, QDateTimeEdit QAbstractItemView {\n"
"  background-color: #FAFAFA;\n"
"  border-radius: 4px;\n"
"  border: 1px solid #C0C4C8;\n"
"  selection-background-col"
                        "or: #9FCBFF;\n"
"}\n"
"\n"
"/* QAbstractView ----------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"QAbstractView:hover {\n"
"  border: 1px solid #9FCBFF;\n"
"  color: #19232D;\n"
"}\n"
"\n"
"QAbstractView:selected {\n"
"  background: #9FCBFF;\n"
"  color: #C0C4C8;\n"
"}\n"
"\n"
"/* PlotWidget -------------------------------------------------------------\n"
"\n"
"--------------------------------------------------------------------------- */\n"
"PlotWidget {\n"
"  /* Fix cut labels in plots #134 */\n"
"  padding: 0px;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(RoomView);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(RoomView);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        id_label = new QLabel(frame);
        id_label->setObjectName(QString::fromUtf8("id_label"));
        id_label->setStyleSheet(QString::fromUtf8("font-size: 12pt; font-weight: bold;"));
        id_label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(id_label);

        name_label = new QLabel(frame);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setStyleSheet(QString::fromUtf8("font-size: 12pt; font-weight: bold;"));
        name_label->setAlignment(Qt::AlignCenter);
        name_label->setWordWrap(true);

        verticalLayout_2->addWidget(name_label);


        verticalLayout_3->addLayout(verticalLayout_2);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        recordList_label = new QLabel(frame);
        recordList_label->setObjectName(QString::fromUtf8("recordList_label"));
        recordList_label->setStyleSheet(QString::fromUtf8("font-size: 10pt;"));
        recordList_label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(recordList_label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        waiting_radioButton = new QRadioButton(frame);
        waiting_radioButton->setObjectName(QString::fromUtf8("waiting_radioButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(waiting_radioButton->sizePolicy().hasHeightForWidth());
        waiting_radioButton->setSizePolicy(sizePolicy1);
        waiting_radioButton->setMinimumSize(QSize(0, 35));
        waiting_radioButton->setChecked(true);

        verticalLayout->addWidget(waiting_radioButton);

        finished_radioButton = new QRadioButton(frame);
        finished_radioButton->setObjectName(QString::fromUtf8("finished_radioButton"));
        sizePolicy1.setHeightForWidth(finished_radioButton->sizePolicy().hasHeightForWidth());
        finished_radioButton->setSizePolicy(sizePolicy1);
        finished_radioButton->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(finished_radioButton);

        allRecords_radioButton = new QRadioButton(frame);
        allRecords_radioButton->setObjectName(QString::fromUtf8("allRecords_radioButton"));
        sizePolicy1.setHeightForWidth(allRecords_radioButton->sizePolicy().hasHeightForWidth());
        allRecords_radioButton->setSizePolicy(sizePolicy1);
        allRecords_radioButton->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(allRecords_radioButton);


        verticalLayout_3->addLayout(verticalLayout);

        record_listView = new QListView(frame);
        record_listView->setObjectName(QString::fromUtf8("record_listView"));
        record_listView->setSpacing(5);

        verticalLayout_3->addWidget(record_listView);


        horizontalLayout->addWidget(frame);

        frame_2 = new QFrame(RoomView);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        recordId_label = new QLabel(frame_2);
        recordId_label->setObjectName(QString::fromUtf8("recordId_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(recordId_label->sizePolicy().hasHeightForWidth());
        recordId_label->setSizePolicy(sizePolicy2);
        recordId_label->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        recordId_label->setFont(font);
        recordId_label->setStyleSheet(QString::fromUtf8("font-weight: bold;"));
        recordId_label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(recordId_label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        patientId_label = new QLabel(frame_2);
        patientId_label->setObjectName(QString::fromUtf8("patientId_label"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(patientId_label->sizePolicy().hasHeightForWidth());
        patientId_label->setSizePolicy(sizePolicy3);
        patientId_label->setMinimumSize(QSize(135, 40));

        horizontalLayout_3->addWidget(patientId_label);

        patientId_lineEdit = new QLineEdit(frame_2);
        patientId_lineEdit->setObjectName(QString::fromUtf8("patientId_lineEdit"));

        horizontalLayout_3->addWidget(patientId_lineEdit);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        doctorName_label = new QLabel(frame_2);
        doctorName_label->setObjectName(QString::fromUtf8("doctorName_label"));
        sizePolicy3.setHeightForWidth(doctorName_label->sizePolicy().hasHeightForWidth());
        doctorName_label->setSizePolicy(sizePolicy3);
        doctorName_label->setMinimumSize(QSize(0, 40));

        horizontalLayout_4->addWidget(doctorName_label);

        doctorName_lineEdit = new QLineEdit(frame_2);
        doctorName_lineEdit->setObjectName(QString::fromUtf8("doctorName_lineEdit"));

        horizontalLayout_4->addWidget(doctorName_lineEdit);


        horizontalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        primaryDiagnose_label = new QLabel(frame_2);
        primaryDiagnose_label->setObjectName(QString::fromUtf8("primaryDiagnose_label"));
        sizePolicy3.setHeightForWidth(primaryDiagnose_label->sizePolicy().hasHeightForWidth());
        primaryDiagnose_label->setSizePolicy(sizePolicy3);
        primaryDiagnose_label->setMinimumSize(QSize(135, 40));

        horizontalLayout_6->addWidget(primaryDiagnose_label);

        primaryDiagnose_lineEdit = new QLineEdit(frame_2);
        primaryDiagnose_lineEdit->setObjectName(QString::fromUtf8("primaryDiagnose_lineEdit"));

        horizontalLayout_6->addWidget(primaryDiagnose_lineEdit);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        secondaryDiagnose_label = new QLabel(frame_2);
        secondaryDiagnose_label->setObjectName(QString::fromUtf8("secondaryDiagnose_label"));
        sizePolicy3.setHeightForWidth(secondaryDiagnose_label->sizePolicy().hasHeightForWidth());
        secondaryDiagnose_label->setSizePolicy(sizePolicy3);
        secondaryDiagnose_label->setMinimumSize(QSize(135, 40));

        horizontalLayout_7->addWidget(secondaryDiagnose_label);

        secondaryDiagnose_lineEdit = new QLineEdit(frame_2);
        secondaryDiagnose_lineEdit->setObjectName(QString::fromUtf8("secondaryDiagnose_lineEdit"));

        horizontalLayout_7->addWidget(secondaryDiagnose_lineEdit);


        verticalLayout_4->addLayout(horizontalLayout_7);

        buttonBox = new QDialogButtonBox(frame_2);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        verticalLayout_5->addLayout(verticalLayout_4);

        line_2 = new QFrame(frame_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        tabWidget = new QTabWidget(frame_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        patientInfo_tab = new QWidget();
        patientInfo_tab->setObjectName(QString::fromUtf8("patientInfo_tab"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(patientInfo_tab->sizePolicy().hasHeightForWidth());
        patientInfo_tab->setSizePolicy(sizePolicy4);
        horizontalLayout_20 = new QHBoxLayout(patientInfo_tab);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(-1, -1, -1, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, -1, -1, 8);
        personalInfo_groupBox = new QGroupBox(patientInfo_tab);
        personalInfo_groupBox->setObjectName(QString::fromUtf8("personalInfo_groupBox"));
        gridLayout_5 = new QGridLayout(personalInfo_groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(20);
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        patientId_label_2 = new QLabel(personalInfo_groupBox);
        patientId_label_2->setObjectName(QString::fromUtf8("patientId_label_2"));
        sizePolicy3.setHeightForWidth(patientId_label_2->sizePolicy().hasHeightForWidth());
        patientId_label_2->setSizePolicy(sizePolicy3);
        patientId_label_2->setMinimumSize(QSize(107, 0));

        horizontalLayout_31->addWidget(patientId_label_2);

        patientId_lineEdit_2 = new QLineEdit(personalInfo_groupBox);
        patientId_lineEdit_2->setObjectName(QString::fromUtf8("patientId_lineEdit_2"));

        horizontalLayout_31->addWidget(patientId_lineEdit_2);


        gridLayout_5->addLayout(horizontalLayout_31, 0, 0, 1, 1);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        patientName_label = new QLabel(personalInfo_groupBox);
        patientName_label->setObjectName(QString::fromUtf8("patientName_label"));
        sizePolicy3.setHeightForWidth(patientName_label->sizePolicy().hasHeightForWidth());
        patientName_label->setSizePolicy(sizePolicy3);
        patientName_label->setMinimumSize(QSize(85, 0));

        horizontalLayout_32->addWidget(patientName_label);

        patientName_lineEdit_3 = new QLineEdit(personalInfo_groupBox);
        patientName_lineEdit_3->setObjectName(QString::fromUtf8("patientName_lineEdit_3"));

        horizontalLayout_32->addWidget(patientName_lineEdit_3);


        gridLayout_5->addLayout(horizontalLayout_32, 0, 1, 1, 1);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        gender_label = new QLabel(personalInfo_groupBox);
        gender_label->setObjectName(QString::fromUtf8("gender_label"));
        sizePolicy3.setHeightForWidth(gender_label->sizePolicy().hasHeightForWidth());
        gender_label->setSizePolicy(sizePolicy3);
        gender_label->setMinimumSize(QSize(107, 0));

        horizontalLayout_33->addWidget(gender_label);

        gender_comboBox = new QComboBox(personalInfo_groupBox);
        gender_comboBox->addItem(QString());
        gender_comboBox->addItem(QString());
        gender_comboBox->setObjectName(QString::fromUtf8("gender_comboBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(gender_comboBox->sizePolicy().hasHeightForWidth());
        gender_comboBox->setSizePolicy(sizePolicy5);

        horizontalLayout_33->addWidget(gender_comboBox);


        gridLayout_5->addLayout(horizontalLayout_33, 1, 0, 1, 1);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        dob_label = new QLabel(personalInfo_groupBox);
        dob_label->setObjectName(QString::fromUtf8("dob_label"));
        sizePolicy3.setHeightForWidth(dob_label->sizePolicy().hasHeightForWidth());
        dob_label->setSizePolicy(sizePolicy3);
        dob_label->setMinimumSize(QSize(85, 0));

        horizontalLayout_34->addWidget(dob_label);

        dob_dateEdit = new QDateEdit(personalInfo_groupBox);
        dob_dateEdit->setObjectName(QString::fromUtf8("dob_dateEdit"));
        sizePolicy5.setHeightForWidth(dob_dateEdit->sizePolicy().hasHeightForWidth());
        dob_dateEdit->setSizePolicy(sizePolicy5);
        dob_dateEdit->setCalendarPopup(true);

        horizontalLayout_34->addWidget(dob_dateEdit);


        gridLayout_5->addLayout(horizontalLayout_34, 1, 1, 1, 1);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        phone_label = new QLabel(personalInfo_groupBox);
        phone_label->setObjectName(QString::fromUtf8("phone_label"));
        sizePolicy3.setHeightForWidth(phone_label->sizePolicy().hasHeightForWidth());
        phone_label->setSizePolicy(sizePolicy3);
        phone_label->setMinimumSize(QSize(107, 0));

        horizontalLayout_35->addWidget(phone_label);

        phone_lineEdit = new QLineEdit(personalInfo_groupBox);
        phone_lineEdit->setObjectName(QString::fromUtf8("phone_lineEdit"));

        horizontalLayout_35->addWidget(phone_lineEdit);


        gridLayout_5->addLayout(horizontalLayout_35, 2, 0, 1, 1);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        address_label = new QLabel(personalInfo_groupBox);
        address_label->setObjectName(QString::fromUtf8("address_label"));
        sizePolicy3.setHeightForWidth(address_label->sizePolicy().hasHeightForWidth());
        address_label->setSizePolicy(sizePolicy3);
        address_label->setMinimumSize(QSize(85, 0));

        horizontalLayout_36->addWidget(address_label);

        address_lineEdit = new QLineEdit(personalInfo_groupBox);
        address_lineEdit->setObjectName(QString::fromUtf8("address_lineEdit"));

        horizontalLayout_36->addWidget(address_lineEdit);


        gridLayout_5->addLayout(horizontalLayout_36, 2, 1, 1, 1);

        gridLayout_5->setColumnStretch(0, 4);
        gridLayout_5->setColumnStretch(1, 5);

        verticalLayout_8->addWidget(personalInfo_groupBox);

        symptom_frame = new QFrame(patientInfo_tab);
        symptom_frame->setObjectName(QString::fromUtf8("symptom_frame"));
        symptom_frame->setFrameShape(QFrame::StyledPanel);
        symptom_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_41 = new QHBoxLayout(symptom_frame);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        symptom_label = new QLabel(symptom_frame);
        symptom_label->setObjectName(QString::fromUtf8("symptom_label"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(symptom_label->sizePolicy().hasHeightForWidth());
        symptom_label->setSizePolicy(sizePolicy6);
        symptom_label->setMinimumSize(QSize(95, 0));
        symptom_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_41->addWidget(symptom_label);

        symptom_plainTextEdit = new QPlainTextEdit(symptom_frame);
        symptom_plainTextEdit->setObjectName(QString::fromUtf8("symptom_plainTextEdit"));

        horizontalLayout_41->addWidget(symptom_plainTextEdit);


        verticalLayout_8->addWidget(symptom_frame);

        verticalLayout_8->setStretch(0, 3);
        verticalLayout_8->setStretch(1, 2);

        horizontalLayout_20->addLayout(verticalLayout_8);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, -1, -1, 4);
        insuranceInfo_groupBox = new QGroupBox(patientInfo_tab);
        insuranceInfo_groupBox->setObjectName(QString::fromUtf8("insuranceInfo_groupBox"));
        insuranceInfo_groupBox->setEnabled(true);
        verticalLayout_7 = new QVBoxLayout(insuranceInfo_groupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        cardId_label = new QLabel(insuranceInfo_groupBox);
        cardId_label->setObjectName(QString::fromUtf8("cardId_label"));
        sizePolicy3.setHeightForWidth(cardId_label->sizePolicy().hasHeightForWidth());
        cardId_label->setSizePolicy(sizePolicy3);
        cardId_label->setMinimumSize(QSize(102, 0));

        horizontalLayout_38->addWidget(cardId_label);

        cardId_lineEdit = new QLineEdit(insuranceInfo_groupBox);
        cardId_lineEdit->setObjectName(QString::fromUtf8("cardId_lineEdit"));
        sizePolicy5.setHeightForWidth(cardId_lineEdit->sizePolicy().hasHeightForWidth());
        cardId_lineEdit->setSizePolicy(sizePolicy5);

        horizontalLayout_38->addWidget(cardId_lineEdit);


        verticalLayout_7->addLayout(horizontalLayout_38);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        issueDate_label = new QLabel(insuranceInfo_groupBox);
        issueDate_label->setObjectName(QString::fromUtf8("issueDate_label"));
        sizePolicy3.setHeightForWidth(issueDate_label->sizePolicy().hasHeightForWidth());
        issueDate_label->setSizePolicy(sizePolicy3);
        issueDate_label->setMinimumSize(QSize(102, 0));

        horizontalLayout_37->addWidget(issueDate_label);

        issueDate_dateEdit = new QDateEdit(insuranceInfo_groupBox);
        issueDate_dateEdit->setObjectName(QString::fromUtf8("issueDate_dateEdit"));
        sizePolicy5.setHeightForWidth(issueDate_dateEdit->sizePolicy().hasHeightForWidth());
        issueDate_dateEdit->setSizePolicy(sizePolicy5);
        issueDate_dateEdit->setCalendarPopup(true);

        horizontalLayout_37->addWidget(issueDate_dateEdit);


        verticalLayout_7->addLayout(horizontalLayout_37);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        expiryDate_label = new QLabel(insuranceInfo_groupBox);
        expiryDate_label->setObjectName(QString::fromUtf8("expiryDate_label"));
        sizePolicy3.setHeightForWidth(expiryDate_label->sizePolicy().hasHeightForWidth());
        expiryDate_label->setSizePolicy(sizePolicy3);
        expiryDate_label->setMinimumSize(QSize(102, 0));

        horizontalLayout_39->addWidget(expiryDate_label);

        expiryDate_dateEdit = new QDateEdit(insuranceInfo_groupBox);
        expiryDate_dateEdit->setObjectName(QString::fromUtf8("expiryDate_dateEdit"));
        sizePolicy5.setHeightForWidth(expiryDate_dateEdit->sizePolicy().hasHeightForWidth());
        expiryDate_dateEdit->setSizePolicy(sizePolicy5);
        expiryDate_dateEdit->setCalendarPopup(true);

        horizontalLayout_39->addWidget(expiryDate_dateEdit);


        verticalLayout_7->addLayout(horizontalLayout_39);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        coveragePercent_label = new QLabel(insuranceInfo_groupBox);
        coveragePercent_label->setObjectName(QString::fromUtf8("coveragePercent_label"));
        sizePolicy3.setHeightForWidth(coveragePercent_label->sizePolicy().hasHeightForWidth());
        coveragePercent_label->setSizePolicy(sizePolicy3);
        coveragePercent_label->setMinimumSize(QSize(102, 0));

        horizontalLayout_40->addWidget(coveragePercent_label);

        coveragePercent_doubleSpinBox = new QDoubleSpinBox(insuranceInfo_groupBox);
        coveragePercent_doubleSpinBox->setObjectName(QString::fromUtf8("coveragePercent_doubleSpinBox"));
        sizePolicy5.setHeightForWidth(coveragePercent_doubleSpinBox->sizePolicy().hasHeightForWidth());
        coveragePercent_doubleSpinBox->setSizePolicy(sizePolicy5);
        coveragePercent_doubleSpinBox->setMaximum(100.000000000000000);
        coveragePercent_doubleSpinBox->setSingleStep(5.000000000000000);

        horizontalLayout_40->addWidget(coveragePercent_doubleSpinBox);


        verticalLayout_7->addLayout(horizontalLayout_40);


        verticalLayout_6->addWidget(insuranceInfo_groupBox);


        horizontalLayout_20->addLayout(verticalLayout_6);

        horizontalLayout_20->setStretch(0, 2);
        horizontalLayout_20->setStretch(1, 1);
        tabWidget->addTab(patientInfo_tab, QString());
        paraclinicalSpecifying_tab = new QWidget();
        paraclinicalSpecifying_tab->setObjectName(QString::fromUtf8("paraclinicalSpecifying_tab"));
        verticalLayout_9 = new QVBoxLayout(paraclinicalSpecifying_tab);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        quickSpecify_label = new QLabel(paraclinicalSpecifying_tab);
        quickSpecify_label->setObjectName(QString::fromUtf8("quickSpecify_label"));
        sizePolicy3.setHeightForWidth(quickSpecify_label->sizePolicy().hasHeightForWidth());
        quickSpecify_label->setSizePolicy(sizePolicy3);

        horizontalLayout_42->addWidget(quickSpecify_label);

        quickSpecify_comboBox = new QComboBox(paraclinicalSpecifying_tab);
        quickSpecify_comboBox->setObjectName(QString::fromUtf8("quickSpecify_comboBox"));

        horizontalLayout_42->addWidget(quickSpecify_comboBox);


        verticalLayout_9->addLayout(horizontalLayout_42);

        specifiedTests_tableView = new QTableView(paraclinicalSpecifying_tab);
        specifiedTests_tableView->setObjectName(QString::fromUtf8("specifiedTests_tableView"));

        verticalLayout_9->addWidget(specifiedTests_tableView);

        tabWidget->addTab(paraclinicalSpecifying_tab, QString());
        precribe_tab = new QWidget();
        precribe_tab->setObjectName(QString::fromUtf8("precribe_tab"));
        verticalLayout_10 = new QVBoxLayout(precribe_tab);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setSpacing(20);
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        precribedDate_label = new QLabel(precribe_tab);
        precribedDate_label->setObjectName(QString::fromUtf8("precribedDate_label"));
        sizePolicy3.setHeightForWidth(precribedDate_label->sizePolicy().hasHeightForWidth());
        precribedDate_label->setSizePolicy(sizePolicy3);

        horizontalLayout_44->addWidget(precribedDate_label);

        precribedDate_dateEdit = new QDateEdit(precribe_tab);
        precribedDate_dateEdit->setObjectName(QString::fromUtf8("precribedDate_dateEdit"));
        precribedDate_dateEdit->setCalendarPopup(true);

        horizontalLayout_44->addWidget(precribedDate_dateEdit);


        horizontalLayout_45->addLayout(horizontalLayout_44);

        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        precribingDoctorName_label = new QLabel(precribe_tab);
        precribingDoctorName_label->setObjectName(QString::fromUtf8("precribingDoctorName_label"));
        sizePolicy3.setHeightForWidth(precribingDoctorName_label->sizePolicy().hasHeightForWidth());
        precribingDoctorName_label->setSizePolicy(sizePolicy3);

        horizontalLayout_43->addWidget(precribingDoctorName_label);

        precribingDoctorName_lineEdit = new QLineEdit(precribe_tab);
        precribingDoctorName_lineEdit->setObjectName(QString::fromUtf8("precribingDoctorName_lineEdit"));

        horizontalLayout_43->addWidget(precribingDoctorName_lineEdit);


        horizontalLayout_45->addLayout(horizontalLayout_43);

        quickPrecribe_pushButton = new QPushButton(precribe_tab);
        quickPrecribe_pushButton->setObjectName(QString::fromUtf8("quickPrecribe_pushButton"));
        QSizePolicy sizePolicy7(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(quickPrecribe_pushButton->sizePolicy().hasHeightForWidth());
        quickPrecribe_pushButton->setSizePolicy(sizePolicy7);
        quickPrecribe_pushButton->setMinimumSize(QSize(130, 28));

        horizontalLayout_45->addWidget(quickPrecribe_pushButton);


        verticalLayout_10->addLayout(horizontalLayout_45);

        precibedMedicines_tableWidget = new QTableWidget(precribe_tab);
        precibedMedicines_tableWidget->setObjectName(QString::fromUtf8("precibedMedicines_tableWidget"));

        verticalLayout_10->addWidget(precibedMedicines_tableWidget);

        tabWidget->addTab(precribe_tab, QString());

        verticalLayout_5->addWidget(tabWidget);

        verticalLayout_5->setStretch(0, 2);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 3);

        horizontalLayout->addWidget(frame_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        retranslateUi(RoomView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RoomView);
    } // setupUi

    void retranslateUi(QWidget *RoomView)
    {
        RoomView->setWindowTitle(QCoreApplication::translate("RoomView", "RoomView", nullptr));
        id_label->setText(QCoreApplication::translate("RoomView", "<M\303\243 ph\303\262ng>", nullptr));
        name_label->setText(QCoreApplication::translate("RoomView", "<T\303\252n ph\303\262ng>", nullptr));
        recordList_label->setText(QCoreApplication::translate("RoomView", "Danh s\303\241ch ti\341\272\277p nh\341\272\255n", nullptr));
        waiting_radioButton->setText(QCoreApplication::translate("RoomView", "\304\220ang ch\341\273\235", nullptr));
        finished_radioButton->setText(QCoreApplication::translate("RoomView", "Kh\303\241m xong", nullptr));
        allRecords_radioButton->setText(QCoreApplication::translate("RoomView", "T\341\272\245t c\341\272\243", nullptr));
        recordId_label->setText(QCoreApplication::translate("RoomView", "<M\303\243 h\341\273\223 s\306\241>", nullptr));
        patientId_label->setText(QCoreApplication::translate("RoomView", "M\303\243 b\341\273\207nh nh\303\242n:", nullptr));
        doctorName_label->setText(QCoreApplication::translate("RoomView", "T\303\252n b\303\241c s\304\251:", nullptr));
        primaryDiagnose_label->setText(QCoreApplication::translate("RoomView", "Chu\341\272\251n \304\221o\303\241n ch\303\255nh:", nullptr));
        secondaryDiagnose_label->setText(QCoreApplication::translate("RoomView", "Chu\341\272\251n \304\221o\303\241n ph\341\273\245:", nullptr));
        personalInfo_groupBox->setTitle(QCoreApplication::translate("RoomView", "Th\303\264ng tin b\341\273\207nh nh\303\242n", nullptr));
        patientId_label_2->setText(QCoreApplication::translate("RoomView", "M\303\243 b\341\273\207nh nh\303\242n:", nullptr));
        patientName_label->setText(QCoreApplication::translate("RoomView", "H\341\273\215 t\303\252n:", nullptr));
        gender_label->setText(QCoreApplication::translate("RoomView", "Gi\341\273\233i t\303\255nh:", nullptr));
        gender_comboBox->setItemText(0, QCoreApplication::translate("RoomView", "Nam", nullptr));
        gender_comboBox->setItemText(1, QCoreApplication::translate("RoomView", "N\341\273\257", nullptr));

        dob_label->setText(QCoreApplication::translate("RoomView", "Ng\303\240y sinh:", nullptr));
        phone_label->setText(QCoreApplication::translate("RoomView", "S\341\273\221 \304\221i\341\273\207n tho\341\272\241i:", nullptr));
        address_label->setText(QCoreApplication::translate("RoomView", "\304\220\341\273\213a ch\341\273\211:", nullptr));
        symptom_label->setText(QCoreApplication::translate("RoomView", "Tri\341\273\207u ch\341\273\251ng:", nullptr));
        insuranceInfo_groupBox->setTitle(QCoreApplication::translate("RoomView", "Th\303\264ng tin b\341\272\243o hi\341\273\203m", nullptr));
        cardId_label->setText(QCoreApplication::translate("RoomView", "M\303\243 th\341\272\273:", nullptr));
        issueDate_label->setText(QCoreApplication::translate("RoomView", "Ng\303\240y c\341\272\245p:", nullptr));
        expiryDate_label->setText(QCoreApplication::translate("RoomView", "Ng\303\240y h\341\272\277t h\341\272\241n:", nullptr));
        coveragePercent_label->setText(QCoreApplication::translate("RoomView", "M\341\273\251c h\341\273\227 tr\341\273\243:", nullptr));
        coveragePercent_doubleSpinBox->setSuffix(QCoreApplication::translate("RoomView", " %", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(patientInfo_tab), QCoreApplication::translate("RoomView", "Th\303\264ng tin b\341\273\207nh nh\303\242n", nullptr));
        quickSpecify_label->setText(QCoreApplication::translate("RoomView", "Ch\341\273\211 \304\221\341\273\213nh nhanh:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(paraclinicalSpecifying_tab), QCoreApplication::translate("RoomView", "Ch\341\273\211 \304\221\341\273\213nh c\341\272\255n l\303\242m s\303\240n", nullptr));
        precribedDate_label->setText(QCoreApplication::translate("RoomView", "Ng\303\240y k\303\252:", nullptr));
        precribingDoctorName_label->setText(QCoreApplication::translate("RoomView", "T\303\252n b\303\241c s\304\251 k\303\252:", nullptr));
        quickPrecribe_pushButton->setText(QCoreApplication::translate("RoomView", "K\303\252 thu\341\273\221c nhanh", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(precribe_tab), QCoreApplication::translate("RoomView", "K\303\252 thu\341\273\221c", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomView: public Ui_RoomView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMVIEW_H
