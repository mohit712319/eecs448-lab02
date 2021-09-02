/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO 
		Fix this method
	*/
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	int sizecheck=0;
	if(m_size!=0)
	{
		
		do{
			if(temp->getValue()==value)
			{
		 		isFound= true;
			}
			else
			{
				temp=temp->getNext();
				sizecheck=sizecheck+1;
			}
		}while(sizecheck<m_size && isFound==false);
	}
		

	/** TODO 
		Fix this method
	*/

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;
	lastNode=m_front;
	if(m_size==1)
	{
		m_front=nullptr;
		delete lastNode;	
	}
	if(m_size==2)
	{
		lastNode=lastNode->getNext();
		m_front->setNext(nullptr);
		delete lastNode;
		
	}
	if(m_size>2)
	{
		secondintoLast=m_front;
		for(int i=0;i<(m_size-1);i++)//move lastNode so it points the last Node in the list
		{
			lastNode=lastNode->getNext();
		}
		for(int i=0;i<(m_size-2);i++)//move secondintoLast so it points to second to last Node
		{
			secondintoLast=secondintoLast->getNext();
		}
		secondintoLast->setNext(nullptr);
		delete lastNode;
		secondintoLast=nullptr;
		m_size=m_size-1;
		isRemoved=true;
	}
	
			
		
	   
	/** TODO 
		Fix this method
	*/

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
