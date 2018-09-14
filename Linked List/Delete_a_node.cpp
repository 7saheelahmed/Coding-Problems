// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode* target = head;
    if(position == 0){
        head = target->next;
        free(target);
    }
    else{
        for(int i =0;i<position-1;i++){
            target = target->next;    
        }
        SinglyLinkedListNode* temp = target->next;
        target->next = temp->next;
        free(temp);
    }
    return head;
}