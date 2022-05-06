#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)
#include <string>
#include <optional>
#include <vector>

// The <signature> types and declarations
namespace dte2600 {

    namespace detail {
        inline
            std::optional<int>
            findIndexOfFirst(std::vector<char> const& data, char c)
            {
                auto const begin = data.begin();
                auto const end = data.end();
                auto const itr = std::find(begin, end, c);
                if (itr != end) return std::distance(begin, itr);
                return {};
            }
    }

    class string {
    public:
        using CharVec = std::vector<char>;

        string(); // creats an empty string

        void           appendChar(char c);
        size_t         size() const;
        CharVec const& data() const;

        std::optional<int> indexOfFirst(char c) const; //<--sånn det står på nett
        

    private:
        CharVec m_data;
    };

} // namespace dte2600

std::string     toStdString(dte2600::string const& str);
dte2600::string toDte2600String(std::string const& str);

int computeScoreFromString(dte2600::string const& str, char a, char b, char c);


#endif // HEADER_H