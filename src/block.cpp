/**
 * @author Francesco Disperati
 *
 * Released under GNU GPLv3 (http://www.gnu.org/licenses/gpl-3.0.txt)
 */

#include <dm/block.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
using namespace std;


namespace DM {

Block::Block(int id)
  : m_id(id), m_revision(0), m_data(NULL) {}

Block& Block::operator=(const Block &b) {
  if (this == &b)
    return *this;

  m_id = b.m_id;
  m_revision = b.m_revision;
  memcpy(m_data, b.m_data, M_SIZE);
  return *this;
}

int Block::size() const {
  return M_SIZE;
}

int Block::id() const {
  return m_id;
}

int Block::revision() const {
  return m_revision;
}

void* Block::data() const {
  return (void*) m_data;
}

void Block::revision(int rev) {
  m_revision = rev;
}

void Block::data(const void* data) {
  memcpy(m_data, data, M_SIZE);
}

void Block::add_revision() {
  m_revision++;
}

string Block::dump_hex() const {
  ostringstream out;
  int bytes_per_row = 16;
  for (int i = 0; i < M_SIZE; ++i) {
    out << setw(2) << setfill('0') << hex << (int)m_data[i] << " ";
    if ((i+1) % bytes_per_row == 0)
      out << "\n";
  }
  return out.str();
}

} // namespace DM
