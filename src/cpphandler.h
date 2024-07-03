#ifndef CPPHANDLER_H
#define CPPHANDLER_H

#include <QObject>

class CppHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString selectedValue READ selectedValue WRITE setSelectedValue NOTIFY selectedValueChanged)

public:
    explicit CppHandler(QObject *parent = nullptr);

    QString selectedValue() const;
    Q_INVOKABLE void setSelectedValue(const QString &value);

signals:
    void selectedValueChanged();

private:
    QString m_selectedValue;
};

#endif // CPPHANDLER_H
