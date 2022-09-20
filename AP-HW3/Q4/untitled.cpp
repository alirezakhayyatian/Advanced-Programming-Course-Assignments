if(h1->father == h2)                       //father
		return true;
	if(h2->father == h1)                     
		return true;



    if(h1->mother == h2)                       //mother
		return true;
	if(h2->mother == h1)                     
		return true;





    if( (h1->father)->father == h2)            //grandfather
		return true;
	if( (h2->father)->father == h1)            //grandson         
		return true;
    

    if( (h1->mother)->father == h2)            //grandfather
		return true;
    if( (h2->mother)->father == h1)            //grandson
		return true;

	

	if( (h1->mother)->mother == h2)            //grandmother
		return true;
	if( (h2->mother)->mother == h1)            //grandson
		return true;


	if( (h1->father)->mother == h2)            //grandmother
		return true;
	if( (h2->father)->mother == h1)            //grandson 
		return true;



	if(h1->father == h2->father)               //brother sister
		return true;

	if(h1->spouse == h2)                       //spouse
		return true;

	if(h1->father == (h2->father)->father)     //uncle nephew
        return true;
    if(h2->father == (h1->father)->father)     //nephew uncle
        return true;

    if(h1->father == (h2->mother)->father)     //uncle nephew
        return true;
    if(h2->father == (h1->mother)->father)     //nephew uncle



    if( (h1->father)->father == (h2->father)->father)     //cousin 
        return true;
    if( (h1->father)->father == (h2->mother)->father)                  
        return true;
    if( (h2->father)->father == (h1->mother)->father)                  
        return true;
    if( (h2->motherc)->father == (h1->mother)->father)                  
        return true;





    if( (h1->souse)->father == (h2->father) )   //brother & sister in law
        return true;

    if( (h2->souse)->father == (h1->father) )    //brother & sister spouse
        return true;






    temp=h1;
    while(temp == nullptr){                       //child & grandson
    	if(temp->father=h2)
    		return true;
    	temp=temp->father;
    }

    temp=h1;
    while(temp == nullptr){                     //child & grandson
    	if(temp->mother=h2)
    		return true;
    	temp=temp->mother;
    }

    temp=h2;
    while(temp == nullptr){                    //father & grandfather
    	if(temp->father=h1)
    		return true;
    	temp=temp->father;
    }

    temp=h2;
    while(temp == nullptr){                   //mother & grandmother
    	if(temp->mother=h1)
    		return true;
    	temp=temp->mother;
    }







Human** temp = new Human*[t2->getNumberOfChildren()]; 
                    for(int d=0; d < t2->getNumberOfChildren() ; d++)
                        temp[d] = t2->children[d];
                    for(int z=0; z < t2->getNumberOfChildren() ; z++)
                    {
                        t2 = t2->children[z];
                    }