#include <QString>
#include <QtTest>
#include <QRegExp>
#include <QStringList>

class TestRegExpTest : public QObject
{
    Q_OBJECT

public:
    TestRegExpTest();

private Q_SLOTS:
    void testCase1();
    void testNormalXml();
    void testSimpleXml();
    void testCombinedXml();
    void testPartlyXml();
};

TestRegExpTest::TestRegExpTest()
{
}

void TestRegExpTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestRegExpTest::testNormalXml()
{
    QRegExp rx("<presence><c xmlns='http://jabber.org/protocol/caps' hash='sha-1' node='https://github.com/qxmpp-project/qxmpp' ver='k38SC26p638xIKXIi2zPpblrpfo='/></presence>");
    QString str = "Offsets: 12 14 99 231 7";
    QStringList list;
    int pos = 0;

    while ((pos = rx.indexIn(str, pos)) != -1) {
        list << rx.cap(1);
        pos += rx.matchedLength();
    }
}

void TestRegExpTest::testSimpleXml()
{

}

void TestRegExpTest::testCombinedXml()
{

}

void TestRegExpTest::testPartlyXml()
{

}

QTEST_APPLESS_MAIN(TestRegExpTest)

#include "tst_testregexptest.moc"
