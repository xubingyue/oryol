#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::IO::URL
    @brief Oryol's URL class
    
    All resource paths in Oryol are expressed as URLs. 
    On creation and assignment, the URL will be
    parsed and indices to its parts will be stored internally, this
    is quite fast. The actual URL string will be stored as a StringAtom.
    Expensive String construction only happens when actually getting
    the URL parts. 
    
    @see URLBuilder
*/
#include "Core/Types.h"
#include "Core/String/StringAtom.h"
#include "Core/Containers/Map.h"
#include "Core/String/String.h"

namespace Oryol {
namespace IO {

class URL
{
public:
    /// default constructor
    URL();
    /// copy constructor
    URL(const URL& rhs);
    /// move constructor
    URL(URL&& rhs);
    /// construct from raw string
    URL(const char* rhs);
    /// construct from StringAtom
    URL(const Core::StringAtom& rhs);
    /// construct from std::string
    URL(const Core::String& rhs);
    
    /// assignment from other URL
    void operator=(const URL& rhs);
    /// move-assign from other URL
    void operator=(URL&& rhs);
    /// assign from raw string
    void operator=(const char* rhs);
    /// assignment from StringAtom
    void operator=(const Core::StringAtom& rhs);
    /// assignment from std::string
    void operator=(const Core::String& rhs);
    
    /// equality
    bool operator==(const URL& rhs);
    /// inequality
    bool operator!=(const URL& rhs);
    
    /// return true if this is a valid, non-empty URL
    bool IsValid() const;
    /// return true if the URL is empty
    bool Empty() const;
    /// get the URL string
    const Core::StringAtom& Get() const;
    
    /// get the scheme string
    Core::String Scheme() const;
    /// get the user string
    Core::String User() const;
    /// get the password string
    Core::String Password() const;
    /// get the host string
    Core::String Host() const;
    /// get the port string
    Core::String Port() const;
    /// get the path string
    Core::String Path() const;
    /// get the fragment string
    Core::String Fragment() const;
    /// get the query component
    Core::Map<Core::String, Core::String> Query() const;
    
private:
    /// parse URL, populates string indices
    bool parseIndices(Core::String urlString);
    /// clear string indices
    void clearIndices();
    /// copy string indices
    void copyIndices(const URL& rhs);
    
    enum {
        schemeStart = 0,
        schemeEnd,
        userStart,
        userEnd,
        pwdStart,
        pwdEnd,
        hostStart,
        hostEnd,
        portStart,
        portEnd,
        pathStart,
        pathEnd,
        fragStart,
        fragEnd,
        queryStart,
        queryEnd,
        
        numIndices,
    };
    
    Core::StringAtom content;
    int16 indices[numIndices];
    bool valid;
};
   
} // namespace IO
} // namespace Oryol