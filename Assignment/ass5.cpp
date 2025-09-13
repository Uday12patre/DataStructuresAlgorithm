// Implement a simple text editor supporting the following functionalities :
// a.Insert text
// b.Delete text
// c.Display text
// d.Search text

#include <ncurses.h>

struct Node
{
    char data;
    Node *prev;
    Node *next;
    Node(char c)
    {
        data = c;
        prev = NULL;
        next = NULL;
    }
};

class TextEditor
{
    Node *head;
    Node *tail;
    Node *cursor;

public:
    TextEditor()
    {
        head = NULL;
        tail = NULL;
        cursor = NULL;
    }

    // insert a character at cursor
    void insertChar(char c)
    {
        Node *n = new Node(c);

        if (head == NULL)
        {
            head = n;
            tail = n;
            cursor = NULL;
        }
        else if (cursor == head)
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
        else
        {
            Node *prevNode;
            if (cursor != NULL)
                prevNode = cursor->prev;
            else
                prevNode = tail;

            n->prev = prevNode;
            if (prevNode != NULL)
            {
                n->next = prevNode->next;
                prevNode->next = n;
            }
            else
            {
                n->next = NULL;
            }

            if (n->next != NULL)
                n->next->prev = n;
            else
                tail = n;
        }

        if (n->next != NULL)
            cursor = n->next;
        else
            cursor = NULL;
    }

    // delete character before cursor
    void backspace()
    {
        if (head == NULL)
            return;

        Node *target;
        if (cursor != NULL)
            target = cursor->prev;
        else
            target = tail;

        if (target == NULL)
            return;

        if (target == head)
            head = target->next;
        if (target == tail)
            tail = target->prev;
        if (target->prev != NULL)
            target->prev->next = target->next;
        if (target->next != NULL)
            target->next->prev = target->prev;

        delete target;
    }

    // move cursor left
    void moveLeft()
    {
        if (cursor != NULL)
            cursor = cursor->prev;
        else
            cursor = tail;
    }

    // move cursor right
    void moveRight()
    {
        if (cursor == NULL && head != NULL)
            cursor = head;
        else if (cursor != NULL)
            cursor = cursor->next;
    }

    // show all text + status bar
    void displayText()
    {
        clear();
        Node *temp = head;

        int line = 1, col = 1;
        int cursorLine = 1, cursorCol = 1;
        int totalChars = 0;

        while (temp != NULL)
        {
            if (temp == cursor)
            {
                cursorLine = line;
                cursorCol = col;
            }

            if (temp->data == '\n')
            {
                addch('\n');
                line++;
                col = 1;
            }
            else
            {
                addch(temp->data);
                col++;
            }

            totalChars++;
            temp = temp->next;
        }

        if (cursor == NULL)
        { // cursor at end
            cursorLine = line;
            cursorCol = col;
            addch('|');
        }

        // ---- Status Bar ----
        int rows, cols;
        getmaxyx(stdscr, rows, cols); // terminal size
        move(rows - 1, 0);            // bottom row
        clrtoeol();                   // clear old bar
        attron(A_REVERSE);            // highlight
        mvprintw(rows - 1, 0, "Line: %d  Col: %d  |  Total Chars: %d",
                 cursorLine, cursorCol, totalChars);
        attroff(A_REVERSE);

        refresh();
    }
};

int main()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    TextEditor editor;
    int ch;

    while ((ch = getch()) != 27)
    { // ESC key to exit
        if (ch == KEY_LEFT)
            editor.moveLeft();
        else if (ch == KEY_RIGHT)
            editor.moveRight();
        else if (ch == KEY_BACKSPACE || ch == 127)
            editor.backspace();
        else if (ch == '\n')
            editor.insertChar('\n'); // Enter for new line
        else if (ch >= 32 && ch <= 126)
            editor.insertChar((char)ch);

        editor.displayText();
    }

    endwin();
    return 0;
}