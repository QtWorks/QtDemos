#include <QCoreApplication>
#include <QXmlReader>
#include <QXmlStreamReader>
#include <QDebug>
#include <QRegExp>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDomComment>
#include <QDomElement>


bool FindElement(const QString &key, const QStringList &parent_list, QXmlStreamReader &reader)
{
    while (reader.readNextStartElement())
    {
        if (reader.name() == key && parent_list.isEmpty())
        {
            return true;
        }
        else if (parent_list.count() > 0 && reader.name() == parent_list.first())
        {
            QStringList parent_list_ = parent_list;
            parent_list_.pop_front();
            return FindElement(key, parent_list_, reader);
        }
        else
        {
            reader.skipCurrentElement();
        }
    }

    return false;
}

QDomElement FindElement(QStringList key_list, const QDomElement &root)
{
    QDomElement elem = root;
    while (!key_list.isEmpty()) {
        elem = elem.firstChildElement(key_list.first());
        key_list.pop_front();
    }

    return elem;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString text = "<message to='33a9f881e99da9eac4c34ed898ced4bf@joywok.com/Desktop' from='33a9f881e99da9eac4c34ed898ced4bf@joywok.com' type='chat' id='E01363DEDF734380B9D1B0EF31CEB2FA'><sent xmlns='urn:xmpp:carbons:2'><forwarded xmlns='urn:xmpp:forward:0'><message to='a81857cecd1bb5739eb959d5519d2df7@joywok.com' from='33a9f881e99da9eac4c34ed898ced4bf@joywok.com/IOS' type='chat' id='E01363DEDF734380B9D1B0EF31CEB2FA' xmlns='jabber:client'><x xmlns='http://joywok.dogesoft.com/status'><status code='123'><json xmlns='urn:xmpp:json:0' jwtype='status'>{&quot;code&quot;:123,&quot;type&quot;:&quot;audiochat&quot;,&quot;time&quot;:15,&quot;audiochat&quot;:{&quot;time&quot;:15,&quot;sender&quot;:{&quot;id&quot;:&quot;33a9f881e99da9eac4c34ed898ced4bf&quot;,&quot;friends_num&quot;:0,&quot;inTheSameDomain&quot;:false,&quot;device_status&quot;:0,&quot;followers_num&quot;:0,&quot;type_enum&quot;:0,&quot;members_num&quot;:0,&quot;posts_num&quot;:0,&quot;del_flag&quot;:0,&quot;networks_overlap&quot;:0,&quot;device_statusEnum&quot;:0,&quot;score&quot;:0,&quot;name&quot;:&quot;咔咔 哇&quot;,&quot;status&quot;:0}}}</json></status></x><body>通话结束，时长 00:15</body></message></forwarded></sent></message>";

    QXmlStreamReader m_reader(text);

    QStringList parent_list;
    parent_list << "sent" << "forwarded" << "message";
    QString key = "message";

    QString from_jid;
    QString message_body;
    int status_code = 0;
    QString status_body;
    QString type;

    QDomDocument doc;
    if (doc.setContent(text))
    {
        QDomElement elem = FindElement(parent_list, doc.documentElement());
        qDebug() << elem.tagName();
        from_jid = elem.attribute("to");
        type = elem.attribute("type");
        QDomElement elem_x = elem.firstChildElement("x");
        if (!elem_x.isNull()) {
            QDomElement elem_status = elem_x.firstChildElement("status");
            status_code = elem_status.attribute("code").toInt();
            status_body = elem_status.text();
            if (status_body.isEmpty()) {
                QDomElement elem_json = elem_status.firstChildElement("json");
                status_body = elem_json.text();
            }
        }

        QDomElement elem_body = elem.firstChildElement("body");
        message_body = elem_body.text();

//        QDomNode node = elem.firstChild();
//        while (!node.isNull()) {
//            qDebug() << node.nodeName() << node.nodeValue() << node.nodeType();
//            if (node.nodeType() == QDomNode::ElementNode) {
//                QDomElement elem_node = node.toElement();
//                qDebug() << elem_node.text();
//            }
//            node = node.nextSibling();
//        }
    }

//    return 0;

//    if (FindElement(key, parent_list, m_reader))
//    {
////            from_jid = m_reader.attributes().value("from").toString();
//        from_jid = m_reader.attributes().value("to").toString();
////            message_uuid = m_reader.attributes().value("id").toString();
//        while (m_reader.readNextStartElement())
//        {
//            QString tagname = m_reader.name().toString();
//            if (tagname == "body")
//            {
//                message_body = m_reader.readElementText();
//            }
//            else if (tagname == "x")
//            {
//                while (m_reader.readNextStartElement())
//                {
//                    QString xname = m_reader.name().toString();
//                    if ("status" == xname)
//                    {
//                        status_code = m_reader.attributes().value("code").toInt();
//                        status_body = m_reader.readElementText();
//                    }
//                }
//            }
//            else if ("json" == tagname)
//            {
//                QString josndata = m_reader.readElementText();
//                QJsonDocument jsonDocument = QJsonDocument::fromJson(josndata.toUtf8());
//                if(!jsonDocument.isNull())
//                {
//                    QJsonObject jsonObject = jsonDocument.object();
//                    status_code = jsonObject.value("code").toInt();
//                }
//                status_body = josndata;
//            }
//        }
//    }

    qDebug() << from_jid << message_body << status_code << status_body;

    return 0;
}
