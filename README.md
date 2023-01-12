# panda.h README
## Set up
Download and put panda.c and panda.h in the Floder which your program at
## Compile
include "panda.h" in your program
gcc panda.c yourfile -o filename
## How to use
### vector
#### declare
define the struct
`Vector(dataType, structName);`
declare the vector
`structName* vectorName = create_vector_structName();`
#### function
##### insert 
Inserts elements at the specified location in the container.
`vectorName->insert(vectorName, index, element);`
##### remove 
Erases the specified elements from the container.
`vectorName->remove(vectorName, index);`
##### set 
Replaces the contents of the container.
`vectorName->set(vectorName, index, element);`
##### get 
Returns a reference to the element at specified location pos. No bounds checking is performed.
`vectorName->get(vectorName, index);`
##### push
Appends the given element value to the end of the container.
`vectorName->push(vectorName, element);`
##### pop
Removes the last element of the container.
`vectorName->pop(vectorName);`
##### back
Returns a reference to the last element in the container.
`vectorName->back(vectorName);`
##### front
Returns a reference to the first element in the container.
`vectorName->front(vectorName);`
##### clear
Erases all elements from the container. After this call, size is zero.
`vectorName->clear(vectorName);`
##### free
free the container
`vectorName->free(vectorName);`
##### resize
reset the capacity of the container
`vectorName->free(vectorName, newSize);`
##### empty
Checks if the container has no elements
`vectorName->empty(vectorName);`
##### swap
Exchanges the contents of the container with those of other
`vectorName->swap(vectorName, index1, index2);`
##### sort
sort the container
`vectorName->sort(vectorName, compareFunction);`
##### size
Returns the number of elements in the container
`vectorName->size;`
### list
#### declare
define the struct
`List(dataType, structName);`
declare the list
`structName* listName = create_list_structName();`
#### function
##### insert 
Inserts elements at the specified location in the container.
`listName->insert(*index, element);`
##### remove 
Erases the specified elements from the container.
`listName->remove(*index);`
##### set 
Replaces the contents of the container.
`listName->set(*index, element);`
##### get 
Returns a reference to the element at specified location pos. No bounds checking is performed.
`listName->get(*index);`
##### push_back
Appends the given element value to the end of the container.
`listName->push_back(listName, element);`
##### push_front
Appends the given element value to the first of the container.
`listName->push_back(listName, element);`
##### pop_back
Removes the last element of the container.
`listName->pop_back(listName);`
##### pop_front
Removes the first element of the container.
`listName->pop_front(listName);`
##### back
Returns a reference to the last element in the container.
`listName->back(listName);`
##### front
Returns a reference to the first element in the container.
`listName->front(listName);`
##### clear
Erases all elements from the container. After this call, size is zero.
`listName->clear(listName);`
##### free
free the container
`listName->free(listName);`
##### empty
Checks if the container has no elements
`listName->empty(listName);`
##### swap
Exchanges the contents of the container with those of other
`listName->swap(listName, index1, index2);`
##### sort
sort the container
`listName->sort(listName, compareFunction);`
##### size
Returns the number of elements in the container
`listName->size;`
### stack
#### declare
define the struct
`Stack(dataType, structName);`
declare the stack
`structName* stackName = create_stack_structName();`
#### function
##### push
Appends the given element value to the end of the container.
`stackName->push(stackName, element);`
##### pop
Removes the last element of the container.
`stackName->pop(stackName);`
##### top
Returns a reference to the last element in the container.
`stackName->top(stackName);`
##### clear
Erases all elements from the container. After this call, size is zero.
`stackName->clear(stackName);`
##### free
free the container
`stackName->free(stackName);`
##### empty
Checks if the container has no elements
`stackName->empty(stackName);`
##### size
Returns the number of elements in the container
`stackName->size;`
### queue
#### declare
define the struct
`Queue(dataType, structName);`
declare the queue
`structName* queueName = create_queue_structName();`
#### function
##### push
Appends the given element value to the end of the container.
`queueName->push(queueName, element);`
##### pop
Removes the first element of the container.
`queueName->pop(queueName);`
##### front
Returns a reference to the first element in the container.
`queueName->front(queueName);`
##### back
Returns a reference to the last element in the container.
`queueName->front(queueName);`
##### clear
Erases all elements from the container. After this call, size is zero.
`queueName->clear(queueName);`
##### free
free the container
`queueName->free(queueName);`
##### empty
Checks if the container has no elements
`queueName->empty(queueName);`
##### size
Returns the number of elements in the container
`queueName->size;`
### priority_queue
define the struct
`Priority_Queue(dataType, structName, compareFunctionofData);`
declare the priorityqueue
`structName* priorityqueueName = create_priority_queue_structName();`
#### function
##### push
Inserts a new element in the priority_queue. The content of this new element is initialized to val.
`priorityqueueName->push(priorityqueueName, element);`
##### pop
Removes the top element of the container.
`priorityqueueName->pop(priorityqueueName);`
##### top
Returns a reference to the first element in the container.
`priorityqueueName->front(priorityqueueName);`
##### clear
Erases all elements from the container. After this call, size is zero.
`priorityqueueName->clear(priorityqueueName);`
##### free
free the container
`priorityqueueName->free(priorityqueueName);`
##### empty
Checks if the container has no elements
`priorityqueueName->empty(priorityqueueName);`
##### size
Returns the number of elements in the container
`priorityqueueName->size;`
### set
define the struct
`Set(dataType, structName, compareFunctionofData);`
declare the set
`structName* setName = create_set_structName();`
#### function
##### insert 
Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
`setName->insert(setName, key);`
##### erase 
Removes specified elements from the container.
`setName->remove(setName, key);`
##### count 
Returns the number of elements with key that compares equivalent to the specified argument.
`setName->count(setName, key);`
##### clear
Erases all elements from the container. After this call, size is zero.
`setName->clear(setName);`
##### free
free the container
`setName->free(setName);`
##### empty
Checks if the container has no elements
`setName->empty(setName);`
##### lowerbound
Returns an iterator pointing to the first element that is not less than key
`setName->lowerbound(setName, key, compareFunction);`
##### upperbound
Returns an iterator pointing to the first element that is greater than key
`setName->upperbound(setName, key, compareFunction);`
##### size
Returns the number of elements in the container
`setName->size;`
### map(WIP)
:::danger
It can't run now
and I don't know why
:::
define the struct
`Map(indexType, valueType, structName, compareFunctionofData);`
declare the map
`structName* mapName = create_map_structName();`
#### function
##### insert 
Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
`mapName->insert(mapName, key);`
##### erase 
Removes specified elements from the container.
`mapName->remove(mapName, key);`
##### count 
Returns the number of elements with key that compares equivalent to the specified argument.
`mapName->count(mapName, key);`
##### value
Returns the elements with key that compares equivalent to the specified argument.
`mapName->val(mapName, key);`
##### set 
Replaces the contents of the container.
`mapName->set(mapName, index, element);`
##### clear
Erases all elements from the container. After this call, size is zero.
`mapName->clear(mapName);`
##### free
free the container
`mapName->free(mapName);`
##### empty
Checks if the container has no elements
`mapName->empty(mapName);`
##### lowerbound
Returns an iterator pointing to the first element that is not less than key
`mapName->lowerbound(mapName, key,  compareFunction);`
##### upperbound
Returns an iterator pointing to the first element that is greater than key
`mapName->upperbound(mapName, key, compareFunction);`
##### size
Returns the number of elements in the container
`mapName->size;`
### lower_bound(\*first, \*last, v)
Returns an iterator pointing to the first element in the range \[first,last) which does not compare less than v.
The elements in the range shall already be sorted according to this same criterion
### upper_bound(\*first, \*last, v)
Returns an iterator pointing to the first element in the range \[first,last) which does compare greater than v.
The elements in the range shall already be sorted according to this same criterion
### sort(\*first, \*last, cmp)
Sorts the elements in the range \[first, last) in non-descending order with cmp.
### swap(a, b)
Exchanges the given values.
### max(a, b)
Returns the greater of the given values.
### min(a, b)
Returns the smaller of the given values.
