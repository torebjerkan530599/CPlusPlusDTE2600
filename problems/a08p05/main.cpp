#include <ranges>
#include <iostream>
#include <bitset>
#include <functional>
#include <numeric>
#include <array>

namespace sr = std::ranges;
namespace sv = std::views;

/************************************
 * Types, declarations and prototypes
 */
class TTTBase {
public:
    using IndexType = size_t;

private:
    enum class Player : IndexType { X = 0ul, O = 1ul };
    Player m_current_player{ Player::X};

protected:
    void      swapCurrentPlayer();
    IndexType currentPlayerIndex() const;

public:

    virtual void printBoard() const = 0;
    virtual bool isLegalMove(IndexType x, IndexType y) const = 0;
    virtual void move(IndexType x, IndexType y) noexcept = 0;
};


template <size_t boardsize_ST>
class TTT final : public TTTBase {
    
    // Sizes and types
    static size_t const constinit N = boardsize_ST;
    static size_t const constinit NxN = N * N;
    using PieceSet = std::bitset<NxN>;
    using Board = std::array<PieceSet, 2ul>;

    // Data
    Board m_pieces;

    // Utils
    PieceSet  concatinatedBoard() const;
    IndexType to1D(IndexType x, IndexType y) const;

public:
    TTT() = default;

    // reimplemented methods
    void printBoard() const override;
    bool isLegalMove(IndexType x, IndexType y) const override;
    void move(IndexType x, IndexType y) noexcept override;
};



/******
 * Main
 */

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    // Read board-size
    int size;
    std::cin >> size;

    // Init board
    std::unique_ptr<TTTBase> ttt_game;
    if (size == 2) ttt_game = std::make_unique<TTT<2ul>>();
    else if (size == 3) ttt_game = std::make_unique<TTT<3ul>>();
    else if (size == 4) ttt_game = std::make_unique<TTT<4ul>>();
    else {
        std::cout << "Illegal Board Size\n";
        return 0;
    }

    // Read moves
    int no_moves;
    std::cin >> no_moves;

    // Apply moves and print states
    for ([[maybe_unused]] auto const c0 : sv::iota(0, no_moves)) {

        int x;
        int y;
        std::cin >> x >> y;
        if (ttt_game->isLegalMove(x, y)) {
            ttt_game->move(x, y);
        }
        else {
            std::cout << "Illegal Move\n";
            return 0;
        }
        
        ttt_game->printBoard();
    }

  


    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}



/*****************
 * Implementations
 */

template <size_t boardsize_ST>
TTT<boardsize_ST>::PieceSet TTT<boardsize_ST>::concatinatedBoard() const
{
    return std::reduce(m_pieces.begin(), m_pieces.end(), PieceSet(),
        std::bit_and<>());
}

template <size_t boardsize_ST>
size_t TTT<boardsize_ST>::to1D(IndexType x, IndexType y) const
{
    //row nr. * #columns + column nr.
    return x * boardsize_ST + y;
}

template <size_t boardsize_ST>
void TTT<boardsize_ST>::printBoard() const
{
    auto const& [X, O] = m_pieces;
    for (size_t const y : sv::iota(0, int(boardsize_ST))) {
        for (size_t const x : sv::iota(0, int(boardsize_ST))) {
            auto const idx_1d = to1D(x, y);
            //bool test1 = currentPlayerIndex() == X.any();
            //bool test2 = currentPlayerIndex() == Y;

            //auto itr = sr::find(X, '1');

            if (X.test(idx_1d))
                std::cout << 'X';
            else if (O.test(idx_1d))
                std::cout << 'O';
            else
                std::cout << ' ';
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    for ([[maybe_unused]] size_t const x : sv::iota(0, int(boardsize_ST * 2 - 1))) std::cout << '-';
    std::cout << '\n';
}

template <size_t boardsize_ST>
bool TTT<boardsize_ST>::isLegalMove(IndexType x, IndexType y) const
{
    return true;
    //return (x < boardsize_ST) && (x > 0) && (y < boardsize_ST) && (y > 0);
}

template <size_t boardsize_ST>
void TTT<boardsize_ST>::move(IndexType x, IndexType y) noexcept
{
    m_pieces[0].set(to1D(x, y));
    m_pieces[1].set(to1D(x, y));
    std::cout << '\n';
    std::cout << "X set: " << m_pieces[0] << '\n';
    std::cout << '\n';
    std::cout << "Y set: " << m_pieces[1] << '\n';
    swapCurrentPlayer();
}

void TTTBase::swapCurrentPlayer()
{
    switch (m_current_player) {
    case Player::X:
        m_current_player = Player::O;
        break;
    case Player::O:
        m_current_player = Player::X;
        break;
    }
}

TTTBase::IndexType TTTBase::currentPlayerIndex() const
{
    //IndexType test = IndexType(m_current_player);
    return IndexType(m_current_player);
}
