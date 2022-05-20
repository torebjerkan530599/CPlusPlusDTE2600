// stl
#include <utility>
#include <string>
#include <memory>
#include <unordered_map>


namespace cahd
{
    /////////////
    // Unit Types

    using SizeUnit = double;
    using Size2D = std::pair<SizeUnit, SizeUnit>;
    using PriceUnit = double;



    ///////////
    // Material
    struct Material {
        std::string m_name;
        PriceUnit   m_price;   // per square meter
    };
    using MaterialPtr = std::shared_ptr<Material>;



    ///////
    // Room

    class Room {
    public:
        using FloorMaterial = std::weak_ptr<Material>;
        using WallMaterial = std::weak_ptr<Material>;


        Room(std::string const& name, Size2D const& floor_area,
            SizeUnit room_height, FloorMaterial floor, WallMaterial const& wall);


        std::string const& name() const;

        Size2D const& floorSize() const;
        SizeUnit             roomHeight() const;

        FloorMaterial const& floor() const;
        WallMaterial const& wall() const;

    private:
        std::string   m_name;
        Size2D        m_floor_size;
        SizeUnit      m_room_height;
        FloorMaterial m_floor;
        WallMaterial  m_wall;
    };



    ///////////
    // Room API

    namespace room
    {
        SizeUnit  computeVolume(Room const& room);
        SizeUnit  computeFloorPerimiter(Room const& room);
        SizeUnit  computeFloorArea(Room const& room);
        SizeUnit  computeWallArea(Room const& room);
        PriceUnit computeFloorPrice(Room const& room);
        PriceUnit computeWallPrice(Room const& room);
        PriceUnit computePrice(Room const& room);
    }   // namespace room



    /////////////////
    // House designer

    class HouseDesigner
    {
    public:
        using MaterialName = std::string;
        using FloorMaterialName = MaterialName;
        using WallMaterialName = MaterialName;


        HouseDesigner(std::string name);


        bool addMaterial(std::string const& name, PriceUnit price);
        bool addRoom(std::string const& name, Size2D floor_size,
            SizeUnit wall_height, FloorMaterialName floor_material,
            WallMaterialName wall_material);

        bool removeMaterial(std::string const& name);
        bool removeRoom(std::string const& name);

        std::string const& name() const;

        SizeUnit computeVolume() const;
        SizeUnit computeFloorArea() const;
        SizeUnit computeWallArea() const;
        SizeUnit computePrice() const;

    private:
        using Materials = std::unordered_map<std::string, MaterialPtr>;
        using Rooms = std::unordered_map<std::string, Room>;

        Materials   m_materials;
        Rooms       m_rooms;
        std::string m_name;
    };

}   // namespace cahd
