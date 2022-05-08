
//
//  main.cpp
//  2_add_two_numbers
//
//  Created by 孙永杰 on 2022/4/27.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode( ) : val( 0 ), next( nullptr ) { }
    ListNode( int x ) : val( x ), next( nullptr ) { }
    ListNode( int x, ListNode* next ) : val( x ), next( next ) { }
};

bool g_flag = false;
class solution_2 {
public:
    bool addTwoNode( ListNode* p1, ListNode* p2, bool flag ) {
        int value = p1->val + p2->val + ( flag ? 1 : 0 );
        if ( value >= 10) {
            p1->val = value % 10;
            flag = true;
        }
        else {
            p1->val = value;
            flag = false;
        }
        return flag;
    }
    ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 ) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        //while ( nullptr != p1 && nullptr != p2 )
        while ( nullptr != p1->next && nullptr != p2->next )
        {
            g_flag = addTwoNode( p1, p2, g_flag );
            p1 = p1->next;
            p2 = p2->next;
        }
        return finish( l1, l2, p1, p2, g_flag );
    }
    ListNode* finish( ListNode* l1, ListNode* l2,
                      ListNode* p1, ListNode* p2, bool flag ) {
        if ( p2->next == nullptr && p1->next == nullptr ) {
            g_flag = addTwoNode( p1, p2, flag );
            if ( g_flag ) {
                p1->next = new ListNode(1);
            }
            g_flag = false;
            return l1;
        }
        if ( p2->next == nullptr ) {
            g_flag = addTwoNode( p1, p2, flag );
            if ( g_flag ) {
                p1 = p1->next;
                //while ( p1 && p1->val == 9 ) {
                while ( p1 ) {
                    if ( p1->val == 9) {
                        p1->val = 0;
                        if ( p1->next ) {
                            p1 = p1->next;
                        } else {
                            p1->next = new ListNode(1);
                            break;
                        }
                    } else {
                        ++p1->val;
                        break;
                    }
                }
            }
            g_flag = false;
            return l1;
        }
        g_flag = addTwoNode( p1, p2, flag );
        p1->next = p2->next;
        if ( g_flag ) {
            p1 = p1->next;
            while ( p1 ) {
                if ( p1->val == 9 ) {
                    p1->val = 0;
                    if ( p1->next ) {
                        p1 = p1->next;
                    } else {
                        p1->next = new ListNode(1);
                        break;
                    }
                } else {
                    ++p1->val;
                    break;
                }
            }
        }
        g_flag = false;
        return l1;
    }
};

void printList( ListNode* p ) {
    while ( p ) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main( ) {
    // 9 -> 9 -> 1
    ListNode nnn0( 1 );
    ListNode nnn1( 9, &nnn0 );
    ListNode nnn2( 9, &nnn1 );
    // 1
    ListNode mmm0( 1 );
    printList( &nnn2 );
    printList( &mmm0 );
    solution_2 a;
    ListNode* pList = a.addTwoNumbers( &nnn2, &mmm0 );
    printList( pList );
    std::cout << std::endl;
    // n3 2 -> 4 -> 9
    ListNode nn0( 9 );
    ListNode nn1( 4, &nn0 );
    ListNode nn2( 2, &nn1 );
    // n3 5 -> 6 -> 4 -> 9
    ListNode mm0( 9 );
    ListNode mm1( 4, &mm0 );
    ListNode mm2( 6, &mm1 );
    ListNode mm3( 5, &mm2 );
    printList( &nn2 );
    printList( &mm3 );
    pList = a.addTwoNumbers( &nn2, &mm3 );
    printList( pList );
    std::cout << std::endl;
    
    ListNode r0( 0 );
    ListNode s0( 1 );
    printList( &r0 );
    printList( &s0 );
    pList = a.addTwoNumbers( &r0, &s0 );
    printList( pList );
    std::cout << std::endl;
    
    // n3 2 -> 4 -> 3
    ListNode w1( 3 );
    ListNode w2( 4, &w1 );
    ListNode w3( 2, &w2 );
    // n3 5 -> 6 -> 4
    ListNode e1( 4 );
    ListNode e2( 6, &e1 );
    ListNode e3( 5, &e2 );
    printList( &w3 );
    printList( &e3 );
    pList = a.addTwoNumbers( &w3, &e3 );
    printList( pList );
    std::cout << std::endl;
    
    // n3 2 -> 4 -> 3 -> 1
    ListNode n0( 1 );
    ListNode n1( 3, &n0 );
    ListNode n2( 4, &n1 );
    ListNode n3( 2, &n2 );
    // n3 5 -> 6 -> 4
    ListNode m1( 4 );
    ListNode m2( 6, &m1 );
    ListNode m3( 5, &m2 );
    printList( &n3 );
    printList( &m3 );
    pList = a.addTwoNumbers( &n3, &m3 );
    printList( pList );
    std::cout << std::endl;

    // n3 9 -> 9 -> 9 -> 9
    ListNode k0( 9 );
    ListNode k1( 9, &k0 );
    ListNode k2( 9, &k1 );
    ListNode k3( 9, &k2 );
    // n3 9 -> 9
    ListNode q1( 9 );
    ListNode q2( 9, &q1 );
    printList( &k3 );
    printList( &q2 );
    pList = a.addTwoNumbers( &k3, &q2 );
    printList( pList );
    std::cout << std::endl;
    
    // n3 9 -> 9 -> 9 -> 9
    ListNode kk1( 9 );
    ListNode kk2( 9, &kk1 );
    ListNode kk3( 9, &kk2 );
    // n3 9 -> 9
    ListNode qq1( 9 );
    printList( &kk3 );
    printList( &qq1 );
    pList = a.addTwoNumbers( &kk3, &qq1 );
    printList( pList );
    return 0;
}
