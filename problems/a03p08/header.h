#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <optional>
#include <vector>

// The <signature> globals, types and declaration(s)
constinit const bool DTE2600_STRING_CHECK_RANGE = false; // or true

namespace dte2600 {

    class string {
    public:
        using CharVec = std::vector<char>;

        string(std::string const& str);

        void           appendChar(char c);
        size_t         size() const;
        CharVec const& data() const;

        char getCharAtEx(int index) const;
        std::optional<char> getCharAtOpt(int index) const;
        char getCharAtErrBit(int index) const;
        char getCharAtContracts(int index) const;

    public:
        bool accessError() const;
        void resetAccessErrorState();

    private:
        mutable bool m_access_error{ false }; // True on error
        CharVec m_data;
    };


    inline string::string(std::string const& p_str) {

        m_data.reserve(p_str.size());
        for (auto const& c : p_str)
            m_data.emplace_back(c);
    }

    inline
        void string::appendChar(char c) {
        m_data.push_back(c);
    }

    inline
        size_t string::size() const {
        return m_data.size();
    }

    inline
        string::CharVec const& string::data() const {
        return m_data;
    }

} // namespace dte2600

#endif // HEADER_H