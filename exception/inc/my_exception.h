#include <iostream>


namespace exception{

class Myexception {
  public:
    // Myexception(const char* str);

    virtual const char* what() const noexcept = 0;

    virtual ~Myexception() = default;

};

class RuntimeException : public Myexception {
  public:
    RuntimeException(const char* str);

    const char* what() const noexcept override;
  private:
    std::string string_;
};

class InvalidArgumentsException : public Myexception {
  public:
    InvalidArgumentsException(const char* str);

    const char* what() const noexcept override;
  private:
    std::string string_;
};

class OutofRangeException : public Myexception {
  public:
    OutofRangeException(const char* str);

    const char* what() const noexcept override;
  private:
    std::string string_;
};

} // namespace exception