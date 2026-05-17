#include "BST.h"
#include <iostream>
#include <cassert>

int main() {
    BinarySearchTree bst;

    // ── вставка ──────────────────────────────────────────────────
    bst.insert(5, 5.0);
    bst.insert(3, 3.0);
    bst.insert(7, 7.0);
    bst.insert(3, 3.5);   // дубликат ключа 3
    bst.insert(1, 1.0);
    bst.insert(4, 4.0);
    bst.insert(6, 6.0);
    bst.insert(8, 8.0);

    std::cout << "Размер: " << bst.size() << "\n";  // 8
    assert(bst.size() == 8);

    // ── in-order обход (должен вывести ключи в порядке возрастания) ──
    std::cout << "\nIn-order обход:\n";
    for (auto it = bst.begin(); it != bst.end(); ++it)
        std::cout << "  key=" << it->first << "  val=" << it->second << "\n";

    // ── find ─────────────────────────────────────────────────────
    auto it = bst.find(3);
    assert(it != bst.end());
    assert(it->first == 3);

    // ── equalRange — все узлы с ключом 3 ─────────────────────────
    auto [lo, hi] = bst.equalRange(3);
    int count = 0;
    for (auto i = lo; i != hi; ++i) ++count;
    std::cout << "\nУзлов с ключом 3: " << count << "\n";  // 2
    assert(count == 2);

    // ── min / max по всему дереву ─────────────────────────────────
    std::cout << "min key = " << bst.min()->first << "\n";  // 1
    std::cout << "max key = " << bst.max()->first << "\n";  // 8
    assert(bst.min()->first == 1);
    assert(bst.max()->first == 8);

    // ── min / max значения среди узлов с ключом 3 ─────────────────
    std::cout << "min val for key 3 = " << bst.min(3)->second << "\n";  // 3.0
    std::cout << "max val for key 3 = " << bst.max(3)->second << "\n";  // 3.5
    assert(bst.min(3)->second == 3.0);
    assert(bst.max(3)->second == 3.5);

    // ── удаление ────────────────────────────────────────────────
    bst.erase(3);  // удалить оба узла с ключом 3
    assert(bst.size() == 6);
    assert(bst.find(3) == bst.end());

    bst.erase(5);  // удалить корень
    assert(bst.size() == 5);
    assert(bst.find(5) == bst.end());

    // ── оператор копирования ──────────────────────────────────────
    BinarySearchTree copy(bst);
    assert(copy.size() == bst.size());

    // ── оператор перемещения ──────────────────────────────────────
    BinarySearchTree moved(std::move(copy));
    assert(moved.size() == 5);

    std::cout << "\nВсе тесты пройдены.\n";
    return 0;
}
