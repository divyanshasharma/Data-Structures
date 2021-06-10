// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/


Today we are discussing methods for detectiing the loop in the linked list & removal
First comes the ways to detect loop in the linked list different approaches are:
slowpointer & fast pointer approac
HAsh map in ot=rder to store pre visited nodes
In the linked list has a extra parameter of visited
In the linked list if we dont want to change the structire of predefines node then we can take an extra Node temp & then sabke as we visit a node let its next point to the temp noe 


Removal of Loop
Hashmap if used then : If the next is already visited & make this node's next = to NULL

If We are using Slow & Fast Pointer then there are three approaches for removal of loop:
	1. Worst: In this approach what you can do; 
	Ptr2=LoopNode(Node where the loop is detected)
	Ptr1= Pointeer that we move from the head 
	For every Ptr1: run Ptr2 to its next until Ptr2->next !=Ptr1 || ptr2->next!=Ptr1;
	
	The required point where this loop will be broken is when Ptr2->next=Ptr1;
	in this case do replace ptr2->next with NULL
	
	2. In this approach Keep a count of the size of the loop i.e. number of nodes inside the loop & then start the node from head:
	Check that whether after m distance you re getting the same node or not, if yes then Do the next =NULL
	
	3. Best Approach:
	In this approach we use Floyd Warshall Method, You have to find the loop node first.
	Then as we know distance moved by Fast pointer is double of the disance moved by the slow pointer.
	So start the Slow pointer from head & fast poitner with loopnode
	Increment every pointer by 1 until slow->next!=fast->next
	if initially slow pointer is head & loopnode is also head then move the fast pointer until its next !=head & when this node is found replace its next by NULL
	
	
	
//Floyd's Cycle finding algorithm	
	
	class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *l=NULL,*s=head,*f=head;
        while(s!=NULL && f!=NULL && f->next!=NULL){
            f=f->next->next;
            s=s->next;
            if(f==s){
                l=s;
                break;
            }
        }
        if(l==NULL)return;
        s=head;
        if(s==f){
            while(f->next!=s){
                f=f->next;
            }
            f->next=NULL;
            return;
        }
        while(s->next!=f->next){
            s=s->next;
            f=f->next;
        }
            f->next=NULL;
    }
