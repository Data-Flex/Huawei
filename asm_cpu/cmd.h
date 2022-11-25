

DEF_CMD(hlt,  0, 0, {break;})

DEF_CMD(push, 1, 1, {Push (&stk); })

DEF_CMD(pop,  2, 0, {Pop  (&stk); })

DEF_CMD(add,  3, 0, {Push (&stk,   Pop (&stk) + Pop (&stk)); })

DEF_CMD(sup,  4, 0, {Push (&stk, - Pop (&stk) + Pop (&stk)); })

DEF_CMD(mul,  5, 0, {Push (&stk,   Pop (&stk) * Pop (&stk)); })

DEF_CMD(div,  6, 0, {Push (&stk,   Pop (&stk) / Pop (&stk)); })

DEF_CMD(dump, 7, 0, {StackDump (&stk);})

DEF_CMD(out,  8, 0, {int out = pop(&stk); printf ("%d", out);})
