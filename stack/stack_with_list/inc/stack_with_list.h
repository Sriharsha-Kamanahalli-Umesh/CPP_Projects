#include <iostream>

/**
 * @brief A class that implements a stack using a list.
 * 
 * @tparam T The type of the elements in the stack.
 */
template <typename T>
class StackWithList
{
public:
  /**
   * @brief Default constructor for StackWithList
   */
  StackWithList();

  /**
   * @brief Constructor with initial value for StackWithList
   * @param val Initial value to be stored in the stack
   */
  StackWithList(T val);

  /**
   * @brief Push a new value onto the stack
   * @param node Pointer to the top of the stack
   * @param val Value to be pushed onto the stack
   */
  void push(StackWithList **node, T val);

  /**
   * @brief Pop the top value from the stack
   * @param node Pointer to the top of the stack
   * @throws std::underflow_error if the stack is empty
   */
  void pop(StackWithList **node);

  /**
   * @brief Get the top value of the stack
   * @param node Pointer to the top of the stack
   * @return The top value of the stack
   * @throws std::underflow_error if the stack is empty
   */
  T top(StackWithList *node);

private:
  T data; // Data stored in the node
  StackWithList *next; // Pointer to the next node

  /**
   * @brief Check if the stack is empty
   * @param node Pointer to the top of the stack
   * @return true if the stack is empty, false otherwise
   */
  bool isEmpty(StackWithList *node);
};