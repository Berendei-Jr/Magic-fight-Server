# Magic_fight
## Серверное приложение для игры Magic Fight (логика движка создана [supsun-sockol](https://github.com/supsun-sockol))

Для запуска сети необходимо использовать команду:
```
  net::Server Server(60000);
```
Параметром "60000" является порт.

### Сообщением являются объекты класса Msg.
Конструктор: Msg(uint32_t id, const std::string& msg).
id клиента - СТРОГО uint32_t (назначаются id сервером самостоятельно, во входящих сообщениях будет отображено id клиента, от которого пришло сообщение, нумерация начинается со 100). Тело сообщение: std::string.

### Объект Server имеет следующие методы:
1) bool Ready() - имеется ли хоть одно входящее сообщение.
2) Msg Get() - изъять ссобщение из очереди (вначале надо проверять наличие такового через Ready() ).
3) void Send(const Msg&) - отправить сообщение клиенту (сообщение должно содержать id адресата).
4) size_t NumOfMsgAvailable() - сколько сообщений находятся в очереди.
5) const Msg& Top() - просмотреть верхнее сообщение в очереди.

## Описание структуры

1. Поле представялет из себя шестисвязный список, каждый шестиугольник связан со своими соседями.

2. Используется 2 оси координат. Которые направлены, как показано на рисунке
<code>![coordinates](/images/coordinates.png "Оси координат")</code>

3. <code>![uml](/images/diagram.png "uml")</code>
