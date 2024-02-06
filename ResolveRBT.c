void resolveRBT( RedBlackNodeType **treeRootAddress, RedBlackNodeType *wkgPtr )
{
    
    //declare parentPtr, grandParPtr, unclePtr, grtGrandPtr
    RedBlackNodeType *parentPtr, *grandParPtr, *unclePtr, *grtGrandPtr;
    
    // check for parent and grandparent exists
    //if( wkgPtr->parentPtr != NULL && wkgPtr->parentPtr->parentPtr != NULL )
    {
        //set relatives
        
        //find uncle that matters
        
        //if parent is red then 
        //if( parentPtr->color != BLACK )
        {
            //check for red uncle not null and not black / is red
            //if( unclePtr != NULL && unclePtr->color != BLACK )
            {
                
            }
            //other wise assume uncle is black
            //else 
            {
                //check for parent is left of grandparent
                //if( parentPtr == grandParPtr->leftChildPtr )
                {
                    //check for child is left of parent ( left left case )
                    //if( wkgPtr == parentPtr->leftChildPtr )
                    {
                        //if( grandParPtr->parentPtr != NULL ) 
                        {
                            //rotate right grdParent to Parent 
                        } 
                        //else
                        {
                            //rotate right grdParent to Parent 
                            //and set to root ^^
                            
                        }
                        //swap colors between the Parent and the GrandParent

                    }    
                    //child is right of parent
                    //else
                    {
                        //First, rotate (left) Parent (old top) to Newnode (new top)/
                        //resolve function with parent as newNode
                        //Recursion will treat this as a Left-Left case
                    }
                }            
                
                //otherwise right right case
                //check Parent is right of GrdParent
                //else //( parentPtr == grandParPtr->rightChildPtr )
                {
                    //check child is right of parent
                    //if( wkgPtr == parentPtr->rightChildPtr )
                    {    
                        //if( grandParPtr->parentPtr != NULL  ) 
                        {
                            //Rotate (left) Grandparent (old top) to Parent (new top)
                        }
                        //else 
                        {
                            //Rotate (left) Grandparent (old top) to Parent (new top)
                            //set to root
                        }
                        //Swap colors between Parent and Grandparent
                    }
                    //child is left is of parent
                    //else
                    {
                        //First, rotate (right) Parent (old top) to Newnode (new top)
                        //Then, call resolve function with parent as Newnode
                        //Recursion will treat this as a Right-Right case
                    }
                }
            }
        }
    }
    
    //check for current node is root pointer
    //if( wkgPtr == *treeRootAddress )
    {
        //paint it black
    }
}
