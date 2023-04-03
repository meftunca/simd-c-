#ifndef MMAP_HPP
#define MMAP_HPP
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>

class MemoryMappedFile
{
  public:
  MemoryMappedFile(const std::string& filename)
      : path(filename)
      , filebuf(std::make_unique<std::filebuf>())
  {
    if( !filebuf->open(path, std::ios::in | std::ios::out | std::ios::binary) )
    {
      throw std::runtime_error("Cannot open the file.");
    }

    size = std::filesystem::file_size(path);
  }

  ~MemoryMappedFile()
  {
    if( filebuf ) { filebuf->close(); }
  }

  void read() const
  {
    std::istream is(filebuf.get());
    std::string  content(size, '\0');
    is.read(content.data(), size);
    std::cout << content;
  }

  void write(const std::string& content)
  {
    std::ostream os(filebuf.get());
    os.write(content.data(), content.size());
    os.flush();
    size = content.size();
  }

  void removeFile() const { std::filesystem::remove(path); }

  private:
  std::filesystem::path         path;
  std::unique_ptr<std::filebuf> filebuf;
  std::size_t                   size {0};
};
// #include <fcntl.h>
// #include <iostream>
// #include <unistd.h>

// #include <sys/mman.h>
// #include <sys/stat.h>

// class MemoryMappedFile
// {
//   public:
//   MemoryMappedFile(const std::string& filename) : filename(filename)
//   {
//     fd = open(filename.c_str(), O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
//     if( fd == -1 ) { throw std::runtime_error("Cannot open the file."); }

//     struct stat sb;
//     if( fstat(fd, &sb) == -1 ) { throw std::runtime_error("Cannot obtain file size."); }

//     size = sb.st_size;

//     data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
//     if( data == MAP_FAILED ) { throw std::runtime_error("Cannot mmap the file."); }
//   }

//   ~MemoryMappedFile()
//   {
//     if( data != nullptr ) { munmap(data, size); }

//     if( fd != -1 ) { close(fd); }
//   }

//   char *read() const
//   {
//     // char* content = static_cast<char*>(data);
//     // for (size_t i = 0; i < size; ++i) {
//     //     std::cout << content[i];
//     // }
//     return static_cast<char *>(data);
//   }

//   void write(const std::string& content)
//   {
//     size_t new_size = content.size();

//     if( ftruncate(fd, new_size) == -1 ) { throw std::runtime_error("Cannot resize the file."); }

//     data = mmap(NULL, new_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
//     if( data == MAP_FAILED ) { throw std::runtime_error("Cannot mmap the file."); }

//     memcpy(data, content.c_str(), new_size);

//     size = new_size;
//   }

//   void removeFile() const
//   {
//     if( unlink(filename.c_str()) == -1 ) { throw std::runtime_error("Cannot remove the file."); }
//   }

//   private:
//   int         fd {-1};
//   void       *data {nullptr};
//   size_t      size {0};
//   std::string filename;
// };

#endif // MMAP_HPP