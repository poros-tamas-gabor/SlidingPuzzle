#ifndef SP_EXCEPTION_H
#define SP_EXCEPTION_H
#include <string>

///////////////////////////////////////////////////////////////////////////////
// SPException.h
// ==============
//
// This header file contains the declaration of the SPException class, which is designed to handle exceptions thrown from the application.
// The class has a constructor that takes a message string, the file, function, and line number where the exception occurred.
// The class also overrides the what() method to return the concatenated error message as a wide character string.
//
// AUTHOR: TAMAS GABOR POROS
// CREATED: 2023-08-04
///////////////////////////////////////////////////////////////////////////////

#define THROW_SPEXCEPTION(msg) throw SPException(msg,__FILE__, __FUNCTION__, __LINE__ )
#define THROW_SPEXCEPTION_IF_FAILED(isCorrect, msg) if(!isCorrect) throw SPException(msg,__FILE__, __FUNCTION__, __LINE__ )
class SPException 
{
private:
	std::string m_whatmsg;
public:
	SPException(const std::string& msg, const std::string& file, const std::string& function, int line)
	{
		m_whatmsg = "Message: " + msg + "\n";
		m_whatmsg += "\nFile: " + file;
		m_whatmsg += "\nFunction: " + function;
		m_whatmsg += "\nLine: " + std::to_string(line);
	}

	const char* what() const
	{
		return m_whatmsg.c_str();
	}
};
#endif 