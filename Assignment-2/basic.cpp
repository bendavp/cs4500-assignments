#include "object.h"
#include "queue.h"
#include <assert.h>
#include <string>

int main()
{
    String *s = new String("Test");
    StringQueue *q = new StringQueue();

    q->add(s);
    assert(q->peek()->equals(s));
    for (int i = 0; i < 1000; i++)
    {
        assert(q->size() == i + 1);
        String *bb = new String((std::string("Bopis ") + std::to_string(i)).c_str());
        q->add(bb);
        assert(q->get_el_at(q->size() - 1)->equals(bb));
    }
}
