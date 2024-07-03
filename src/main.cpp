#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <iostream>



class ButtonClickHandler : public QObject
{
    Q_OBJECT
public:
    explicit ButtonClickHandler(QObject *parent = nullptr) : QObject(parent) {}

    QString directoryName;
    QString guess_command;
    QString trans_command;
    QString uniq_command;
    QString split_command;
    QString rm_command;

    QString data_file;
    QString names_file;
    QString txt_file;
    QString mat_file;
    QString unq_file;
    QString ratio;
    QString lrn_file;
    QString chk_file;
    QString seq_or_pthread;
    QString out_file;
    QString formula;
    QString root;
    QString closure;
    QString closure_command;

public slots:

    void handleSelectionChange(const QString &newValue) {

        directoryName = newValue;

        //ROOT
        root = directoryName;


        if(directoryName == "balance-scale")
        {
            root = QString::fromStdString("bsc");
        }
        if(directoryName == "banknote")
        {
            root = QString::fromStdString("ba");
        }
        if(directoryName == "breast-cancer-wisconsin")
        {
            root = QString::fromStdString("bcw");
        }
        if(directoryName == "forest-fire")
        {
            root = QString::fromStdString("ff");
        }
        if(directoryName == "monk")
        {
            root = QString::fromStdString("monks");
        }
        if(directoryName == "vote")
        {
            root = QString::fromStdString("hv84");
        }

        //DATA
        data_file = QString::fromStdString(root.toStdString() + ".data");

        if(directoryName == "accent" || directoryName == "divorce" || directoryName == "forest-fire")
        {
            data_file = QString::fromStdString(root.toStdString() + ".csv");
        }

        //NAMES
        names_file = QString::fromStdString(root.toStdString() + ".names");
        if(directoryName == "abalone" || directoryName == "bean" || directoryName == "rice")
        {
            names_file = QString::fromStdString(root.toStdString() + ".nam");
        }

        //TXT
        txt_file = QString::fromStdString(root.toStdString() + ".txt");

        //MAT
        mat_file = QString::fromStdString(root.toStdString() + ".mat");

        //UNQ
        unq_file = QString::fromStdString(root.toStdString() + ".unq");

        //LRN
        lrn_file = QString::fromStdString(root.toStdString() + ".lrn");

        //CHK
        chk_file = QString::fromStdString(root.toStdString() + ".chk");

        //RATIO
        ratio = QString::fromStdString("20");

        //SEQ OR PTHREAD
        seq_or_pthread = QString::fromStdString("pthread");
        if(directoryName == "balloons" || directoryName == "breast-cancer-wisconsin" || directoryName == "car" || directoryName == "divorce" || directoryName == "forest-fire" || directoryName == "iris" || directoryName == "monk" || directoryName == "mushroom" || directoryName == "vote")
        {
            seq_or_pthread = QString::fromStdString("seq");
        }

        //OUT
        out_file = QString::fromStdString(root.toStdString() + ".out");

        //COMANDS

        std::string command = "cd .. && source ../.zshrc && cd mcp-main && cd uci/"+directoryName.toStdString()+" && mcp-guess   -i "+data_file.toStdString()+" -n "+names_file.toStdString()+" -o dummy.txt && open ./dummy.txt";
        guess_command = QString::fromStdString(command);

        command = "cd .. && source ../.zshrc && cd mcp-main && cd uci/"+directoryName.toStdString()+" && mcp-trans   -i "+data_file.toStdString()+" -m "+txt_file.toStdString()+" && open -t "+mat_file.toStdString()+"";
        trans_command = QString::fromStdString(command);

        command = "cd .. && source ../.zshrc && cd mcp-main && cd uci/"+directoryName.toStdString()+" && mcp-uniq    -i "+mat_file.toStdString()+" && open -t "+unq_file.toStdString()+"";
        uniq_command = QString::fromStdString(command);

        command = "cd .. && source ../.zshrc && cd mcp-main && cd uci/"+directoryName.toStdString()+" && mcp-split   -i "+unq_file.toStdString()+"  --ratio "+ratio.toStdString()+" && open -t "+lrn_file.toStdString()+" && open -t "+chk_file.toStdString()+"";
        split_command = QString::fromStdString(command);

        command = "cd .. && source ../.zshrc && cd mcp-main && cd uci/"+directoryName.toStdString()+" && rm -f *.mat *.unq *.out *.lrn *.chk *.log *.tst *.pvt *.pdx *.pdt";
        rm_command = QString::fromStdString(command);
    }

    //MAKE
    void make() {
        std::string command = "cd .. && source ../.zshrc && cd mcp-main && echo Dobrovece120dinara | sudo -S make no-mpi";
        int result = std::system(command.c_str());
    }
    //GUESS
    void guess() {
        std::string command = guess_command.toStdString();
        int result = std::system(command.c_str());
    }
    //TRANS
    void trans() {
        std::string command = trans_command.toStdString();
        int result = std::system(command.c_str());
    }
    //UNIQ
    void uniq() {
        std::string command = uniq_command.toStdString();
        int result = std::system(command.c_str());
    }
    //SPLIT
    void split() {
        std::string command = split_command.toStdString();
        int result = std::system(command.c_str());
    }
    //SEQ
    void seq(const QString &s1){

        //CLOSURE
        closure = s1;

        //FORMULA
        formula = QString::fromStdString(root.toStdString() + "-" + closure.toStdString());

        closure_command = QString::fromStdString(" --closure "+closure.toStdString());
        if(closure == "hrn")
        { closure_command = QString::fromStdString(""); }

        std::string command = "cd .. && source ../.zshrc && cd mcp-main && cd uci/"+directoryName.toStdString()+" && mcp-"+seq_or_pthread.toStdString()+"     -i "+lrn_file.toStdString()+"  -o "+out_file.toStdString()+"           --formula "+formula.toStdString() + closure_command.toStdString()+" && open -t "+out_file.toStdString()+"";
        int result = std::system(command.c_str());
    }
    //CHECK
    void check(const QString &s1){
        std::string s = s1.toStdString();
        std::string command = "cd .. && source ../.zshrc && cd mcp-main && cd uci/"+directoryName.toStdString()+" && mcp-check   -i "+chk_file.toStdString()+"  -l "+formula.toStdString()+"_"+s+".log    -o "+formula.toStdString()+"_"+s+".out && open -t "+formula.toStdString()+"_"+s+".out";
        int result = std::system(command.c_str());
    }
    //CLEAN
    void clean() {
        std::string command = rm_command.toStdString();
        int result = std::system(command.c_str());
    }

};

int main(int argc, char *argv[])
{


    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    const QUrl url(u"qrc:/qt/qml/Main/main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.addImportPath(":/");

    engine.load(url);

    ButtonClickHandler buttonClickHandler;
    engine.rootContext()->setContextProperty("ButtonClickHandler", &buttonClickHandler);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }


    // Connect the button's clicked signal to the handleButtonClick slot
    QObject *rootObject = engine.rootObjects().first();
    if (rootObject) {

        QObject::connect(rootObject, SIGNAL(selectionChanged(QString)), &buttonClickHandler, SLOT(handleSelectionChange(QString)));

        QObject *make_button = rootObject->findChild<QObject*>("make");
        QObject *guess_button = rootObject->findChild<QObject*>("guess");
        QObject *trans_button = rootObject->findChild<QObject*>("trans");
        QObject *uniq_button  = rootObject->findChild<QObject*>("uniq");
        QObject *split_button = rootObject->findChild<QObject*>("split");
        QObject *clean_button = rootObject->findChild<QObject*>("clean");

        if (make_button) {
            QObject::connect(make_button, SIGNAL(clicked()), &buttonClickHandler, SLOT(make()));
        }
        if (guess_button) {
            QObject::connect(guess_button, SIGNAL(clicked()), &buttonClickHandler, SLOT(guess()));
        }
        if (trans_button) {
            QObject::connect(trans_button, SIGNAL(clicked()), &buttonClickHandler, SLOT(trans()));
        }
        if (uniq_button) {
            QObject::connect(uniq_button, SIGNAL(clicked()), &buttonClickHandler, SLOT(uniq()));
        }
        if (split_button) {
            QObject::connect(split_button, SIGNAL(clicked()), &buttonClickHandler, SLOT(split()));
        }
        if (clean_button) {
            QObject::connect(clean_button, SIGNAL(clicked()), &buttonClickHandler, SLOT(clean()));
        }
    }



    return app.exec();
}

#include "main.moc"
