# Add sources
target_sources(ChessPlusPlus PUBLIC
	"${CMAKE_CURRENT_LIST_DIR}/Debug.cpp"
)

# Divvy out work to subdirectories
add_subdirectory("app/")
add_subdirectory("board/")
add_subdirectory("config/")
add_subdirectory("gfx/")
add_subdirectory("piece/")
add_subdirectory("res/")
add_subdirectory("util/")
