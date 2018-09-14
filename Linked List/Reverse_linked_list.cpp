// Complete the reversePrint function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void reversePrint(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *current;
    SinglyLinkedListNode *future;
    SinglyLinkedListNode *past;
    past = nullptr;
    future = nullptr;
    current = head;
    while(current !=nullptr){
        future=current->next;
        current->next = past;
        past = current;
        current = future;
    }
    head = past;
    SinglyLinkedListNode *temp1 = head;
    while(temp1 !=nullptr){
        cout<<temp1->data<<endl;
        temp1 = temp1->next;
        
    }
    
}