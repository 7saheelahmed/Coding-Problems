// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* last = new SinglyLinkedListNode(data);
    if(head == nullptr){
        head = last;
    }
    else{
        SinglyLinkedListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
            }
        temp->next = last;
    }
    return head;
}