void resolveRBT( RedBlackNodeType **treeRootAddress, RedBlackNodeType *wkgPtr )
{
    
    //declare parentPtr, grandParPtr, unclePtr, grtGrandPtr
    RedBlackNodeType *parentPtr, *grandParPtr, *unclePtr, *grtGrandPtr;
    
    // check for parent and grandparent exists
    if( wkgPtr->parentPtr != NULL && wkgPtr->parentPtr->parentPtr != NULL )
    {
        //set relatives
        parentPtr = wkgPtr->parentPtr;
        grandParPtr = parentPtr->parentPtr;
        
        //find uncle that matters
        if( grandParPtr->rightChildPtr == parentPtr )
        {
            unclePtr = grandParPtr->leftChildPtr;
        }
        else
        {
            unclePtr = grandParPtr->rightChildPtr;
        }
        
        //if parent is red then 
        if( parentPtr->color != BLACK )
        {
            printf("   Parent is RED\n");
            //check for red uncle not null and not black / is red
            if( unclePtr != NULL && unclePtr->color != BLACK )
            {
                printf("   Uncle is RED\n");
                //change parent and uncle to black 
                parentPtr->color = BLACK;
                printf("      Parent is set to BLACK\n");
                unclePtr->color = BLACK;
                printf("      Uncle is set to BLACK\n");
                //change grandparent to red
                grandParPtr->color = RED;
                printf("      grdParent is set to BLACK\n");
                //recurse with the grandparent
                printf("      Resolving GrdParent\n");
                resolveRBT( treeRootAddress, grandParPtr );
            }
            //other wise assume uncle is black
            else 
            {
                //check for parent is left of grandparent
                if( parentPtr == grandParPtr->leftChildPtr )
                {
                    //check for child is left of parent ( left left case )
                    if( wkgPtr == parentPtr->leftChildPtr )
                    {
                        if( grandParPtr->parentPtr != NULL ) 
                        {
                            grtGrandPtr = grandParPtr->parentPtr;
                            //rotate right grdParent to Parent 
                            grtGrandPtr->leftChildPtr = rotateRight( parentPtr, grandParPtr );
                        } 
                        else
                        {
                            //rotate right grdParent to Parent 
                            *treeRootAddress = rotateRight( parentPtr, grandParPtr );
                            //and set to root ^^
                            
                        }
                        //swap colors between the Parent and the GrandParent
                        swapColors( grandParPtr, parentPtr );
                    }    
                    //child is right of parent
                    else
                    {
                        //First, rotate (left) Parent (old top) to Newnode (new top)/
                        grandParPtr->leftChildPtr = rotateLeft( wkgPtr, parentPtr );
                        //resolve function with parent as newNode
                        //Recursion will treat this as a Left-Left case:
                        resolveRBT( treeRootAddress, wkgPtr->leftChildPtr );
                    }
                }            
                
                //otherwise right right case
                //check Parent is right of GrdParent
                else //( parentPtr == grandParPtr->rightChildPtr )
                {
                    //check child is right of parent
                    if( wkgPtr == parentPtr->rightChildPtr )
                    {    
                        if( grandParPtr->parentPtr != NULL  ) 
                        {
                            grtGrandPtr = grandParPtr->parentPtr;
                            //Rotate (left) Grandparent (old top) to Parent (new top)
                            grtGrandPtr->rightChildPtr = rotateLeft( parentPtr, grandParPtr );
                        }
                        else 
                        {
                            //Rotate (left) Grandparent (old top) to Parent (new top)
                            *treeRootAddress = rotateLeft( parentPtr, grandParPtr );
                            //set to root
                        }
                        //Swap colors between Parent and Grandparent
                        swapColors( grandParPtr, parentPtr );
                    }
                    //child is left is of parent
                    else
                    {
                        //First, rotate (right) Parent (old top) to Newnode (new top)
                        grandParPtr->rightChildPtr = rotateRight( wkgPtr, parentPtr );
                        //Then, call resolve function with parent as Newnode
                        //Recursion will treat this as a Right-Right case
                        resolveRBT( treeRootAddress, wkgPtr->rightChildPtr );
                    }
                }
            }
        }
    }
    
    //check for current node is root pointer
    if( wkgPtr == *treeRootAddress )
    {
        //paint it black
        wkgPtr->color = BLACK;
        printf("Root is set to BLACK\n");
    }
     
    displayTreeStructure( *treeRootAddress, NODE_COLOR );
    displayDivider( *treeRootAddress, THIN_DIVIDER );
    displayTreeStructure( *treeRootAddress, NODE_DATA );
    displayDivider( *treeRootAddress, THICK_DIVIDER );
}