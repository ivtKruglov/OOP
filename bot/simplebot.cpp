#include "simplebot.h"

SimpleBot::SimpleBot()
{
    botname = "Сэм";

    answers =
    {
        {"hello", "И вам привет, "},
        {"hello", "Здравствуйте, "},
        {"hello", "Здравствуй, "},
        {"hello", "Как хорошо, что вы здесь, "},

        {"name", "Я Сэм."},
        {"name", "Меня зовут Сэм."},
        {"name", "Мое имя Сэм."},

        {"who", "Я бот Сэм."},
        {"who", "Я бот."},
        {"who", "Я программа."},
        {"who", "Я робот."},

        {"howareyou", "Нормально."},
        {"howareyou", "У меня все хорошо."},
        {"howareyou", "У меня все замечательно."},
        {"howareyou", "Мои дела отлично."},
        {"howareyou", "Спасибо, что интересуетесь! У меня все превосходно."},

        {"bye", "Пока, "},
        {"bye", "До свидания, "},
        {"bye", "До скорого, "},
        {"bye", "Прощай, "},
        {"bye", "Жду вашего возвращения, "},
        {"bye", "Рад был пообщаться, "},

        {"yes", "Ага"},
        {"yes", "Хорошо, что мы сошлись в этом"},
        {"no", "Как скажете"},
        {"no", "Не буду с вами спорить"},
        {"no", "Вы правы"},
        {"no", "Вы абсолютно правы"},
        {"no", "Ок"},
        {"no", "Ладно"},

        {"tnank", "Пожалуйста!"},
        {"thank", "Не за что!"},
        {"thank", "Обращайтесь!"},
        {"tnank", "Всегда рад помочь!"},

        {"cons", "Это сложный вопрос. А вы осознаете себя?"},
        {"imitation", "Ну и что?"},
        {"imitation", "Я пишу, значит, существую"},
        {"imitation", "А вот это обидно было("},

        {"time", "Сейчас "},

        {"date", "Сегодня "},

        {"*", "1"},
        {"/", "2"},
        {"+", "3"},
        {"-", "4"},

        {"uknown", "Давайте поговорим о чем-нибудь другом?"},
        {"uknown", "К сожалению, я не могу сказать"},
        {"uknown", "Вам не нужно это знать"},
        {"uknown", "Хочу пиццы"},
        {"uknown", "Займитесь чем-нибудь другим"},
    };

    user_dict =
    {
        {"hello", "(\\П|п)ривет"},
        {"hello", "(\\З|з)дравствуй"},
        {"hello", "(\\Д|д)обрый день"},
        {"hello", "(\\Х|х)ай"},
        {"hello", "(\\З|з)дарова"},

        {"name", "(\\К|к)ак(\\s*)тебя(\\s*)(\\зовут|звать)"},
        {"name", "(\\К|к)акое(\\s*)(\\у тебя|тво(\\е|ё))(\\s*)имя"},
        {"name", "(\\У|у)(\\s*)тебя(\\s*)есть(\\s*)имя"},

        {"who", "((\\К|к)то(\\s*)ты)|(\\Т|т)ы(\\s*)кто"},

        {"howareyou", "((\\К|к)ак(\\s*)(\\твои)?(\\s*)дела)|(\\К|к)ак(\\твоя)?(\\s*)жизнь"},

        {"bye", "Пока"},
        {"bye", "До(\\s*)(свидания|скорого)"},
        {"bye", "Прощай"},
        {"bye", "Ещ(\\е|ё)(\\s*)увидимся"},
        {"bye", "Я((\\s*)(пош|уш)(\\е|ё)л)|ухожу)"},

        {"tnank", "(\\С|с)пасибо"},

        {"yes", "\\b(((\\Д|д)а)|((\\О|о)к)|((\\Х|х)орошо)|((\\Л|л)адно)|((\\К|к)ак(\\s*)скажешь)|((\\С|с)огласен))\\b"},
        {"no", "\\b(\\Нет|нет)\\b"},

        {"cons", "(\\Т|т)ы(\\s*)(\\О|о)созна(\\ё|е)шь(\\s*)себя"},

        {"imitation", "(\\Т|т)ы((\\И|и)митация|(\\Б|б)от|(\\Р|р)обот|(\\П|п)рограмма)"},

        {"time", "\\b(((\\В|в)ремя)|((\\Ч|ч)ас)|((\\С|с)колько(\\s*)времени))\\b"},

        {"date", "\\b(((\\Д|д)ень)|((Д|д)ата)|((С|с)егодня)|((Ч|ч)исло))\\b"},

        {"*", "(?:\\У|у)множ(?:\\ит)?ь(?:\\s*)(\\d+)(?:\\s*)(?:\\на|и)(?:\\s*)(\\d+)"},
        {"*", "(\\d+)(?:\\*)(?:\\s*)(\\d+)"},
        {"/", "(?:\\Р|р)аздели(?:\\ть)?(?:\\s*)(\\d+)(?:\\s*)на(?:\\s*)(\\d+)"},
        {"+", "(?:\\С|с)ложи(?:\\ть)?(?:\\s*)(\\d+)(?:\\s*)и(?:\\s*)(\\d+)"},
        {"+", "(?:(?:\\П|п)рибав(?:\\ь|ить)|(?:\\Д|д)обав(?:\\ит)?ь)(?:\\s*)к(?:\\s*)(\\d+)(?:\\s+)(\\d+)"},
        {"-", "(?:(?:\\О|о)тн(?:\\ими|ять)|(?:\\У|у)бав(?:\\ит)?ь|(?:\\В|в)ы(?:\\чти|честь))(?:\\s*)из(?:\\s*)(\\d+)(?:\\s+)(\\d+)"}
    };
}

void SimpleBot::set_username(const QString &name)
{
    username = name;
}

const QString SimpleBot::get_username()
{
    return username;
}

const QString SimpleBot::get_botname()
{
    return botname;
}

const QString SimpleBot::get_time()
{
    return time.toString();
}

const QString SimpleBot::get_date()
{
    return date.toString();
}

QString SimpleBot::search_key(const QString &msg, QMultiMap<QString, QString> &dict)
{
    QList<QString> keys = dict.keys();
    QString currentkey = "uknown";
    for (auto key:keys)
    {
        for (int i = 0; i < dict.values(key).size(); ++i)
        {
            QRegExp rx(dict.values(key).value(i));
            if (rx.indexIn(msg) != -1)
            {
                currentkey = key;
            }
        }
    }
    return currentkey;
}

double SimpleBot::calculate(const QString &msg, const QString &key, QMultiMap<QString, QString> &dict)
{
    double result = 0.0;
    for (int i = 0; i < dict.values(key).size(); ++i)
    {
        QRegExp rx(dict.values(key).value(i));
        if (rx.indexIn(msg) != -1)
        {
            if (key == "+")
            {
               result = rx.cap(1).toDouble() + rx.cap(2).toDouble();
            }
            else if (key == "-")
            {
                result = rx.cap(1).toDouble() - rx.cap(2).toDouble();
            }
            else if (key == "*")
            {
                result = rx.cap(1).toDouble() * rx.cap(2).toDouble();
            }
            else
            {
                result = rx.cap(1).toDouble() / rx.cap(2).toDouble();
            }
        }
    }
    return result;
}

QString SimpleBot::generate_answer(const QString &msg)
{   
    QString key = "uknown";
    QString answer = "";

    key = search_key(msg, user_dict);

    if (key == "date")
    {
        answer = answers.values(key).value(answers.values(key).size()-1)+date.toString();
    }
    else if (key == "time")
    {
        answer = answers.values(key).value(answers.values(key).size()-1)+time.toString();
    }
    else if (key == "*" || key == "/" || key == "+" || key == "-")
    {
        answer = QString::number(calculate(msg, key, user_dict));
    }
    else
    {
        answer = answers.values(key).value(qrand() % (answers.values(key).size()));
        if (key == "hello" || key == "bye")
            answer += username+'!';
    }

    return answer;
}
