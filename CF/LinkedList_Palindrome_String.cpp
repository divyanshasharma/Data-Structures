//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#


void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    
    while (current != NULL) 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
    bool comparee(struct Node* head1, struct Node* head2) 
{ 
    struct Node* temp1 = head1; 
    struct Node* temp2 = head2; 

    while (temp1 && temp2)
    { 
        if (temp1->data == temp2->data) 
        { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 

    // Both are empty reurn 1
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 

    // Will reach here when one is NULL 
    // and other is not 
    return 0; 
} 
    bool isPalindrome(Node *head)
    {
        Node*s=head, *f=head, *second_half, *prev_of_slow=head;
        Node *midNode=NULL;
        bool res=true;
        
        if(head!=NULL && head->next!=NULL){
            while(f!=NULL && f->next!=NULL){
                f=f->next->next;
                prev_of_slow=s;
                s=s->next;
            }
        
        if(f!=NULL){
            midNode=s;
            s=s->next;
        }
        
        second_half=s;
        prev_of_slow->next=NULL;//to break the connection with the first part
        reverse(&second_half);
        res=comparee(head,second_half);
        reverse(&second_half);

        if(midNode!=NULL){
            prev_of_slow->next=midNode;
            midNode->next=second_half;
        }
        else{
            prev_of_slow->next=second_half;
        }
        
        }
        return res;
    }
};

