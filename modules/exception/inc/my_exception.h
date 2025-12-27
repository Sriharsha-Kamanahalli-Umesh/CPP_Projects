#include <iostream>

namespace exception {

/**
 * @brief Base class for custom exceptions.
 */
class Myexception {
public:
  /**
   * @brief Get the error message.
   * @return const char* Error message.
   */
  virtual const char *what() const noexcept = 0;

  /**
   * @brief Virtual destructor.
   */
  virtual ~Myexception() = default;
};

/**
 * @brief Exception class for runtime errors.
 */
class RuntimeException : public Myexception {
public:
  /**
   * @brief Constructor.
   * @param str Error message.
   */
  RuntimeException(const char *str);

  /**
   * @brief Get the error message.
   * @return const char* Error message.
   */
  const char *what() const noexcept override;

private:
  std::string string_; ///< Error message
};

/**
 * @brief Exception class for invalid arguments.
 */
class InvalidArgumentsException : public Myexception {
public:
  /**
   * @brief Constructor.
   * @param str Error message.
   */
  InvalidArgumentsException(const char *str);

  /**
   * @brief Get the error message.
   * @return const char* Error message.
   */
  const char *what() const noexcept override;

private:
  std::string string_; ///< Error message
};

/**
 * @brief Exception class for out of range errors.
 */
class OutofRangeException : public Myexception {
public:
  /**
   * @brief Constructor.
   * @param str Error message.
   */
  OutofRangeException(const char *str);

  /**
   * @brief Get the error message.
   * @return const char* Error message.
   */
  const char *what() const noexcept override;

private:
  std::string string_; ///< Error message
};

} // namespace exception