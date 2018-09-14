// Complete the removeDuplicates function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head;
    
    while(temp->next!=nullptr){
        SinglyLinkedListNode* future = temp->next;
        if(temp->data == future->data){
            temp->next = future->next;
            free(future);
        }
        else{
            temp = temp->next;
        }
    }
    return head;

}