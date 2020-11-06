/*  Name: Moez Rjiba
 *  Matrikel-Nr: 837903
 *
 * Links: https://codereview.stackexchange.com/questions/139841/printing-out-vectorstring-char-by-char
 *         https://stackoverflow.com/questions/31016682/vector-and-iterators-print-out-value-instead-of-memory-address
 *         https://github.com/Digiyang/University/tree/master/Informatik%203
 *
 *         I got some help from the Stackoverflow community (this is my post):
 *         https://stackoverflow.com/questions/64715888/getting-error-terminate-called-after-throwing-an-instance-of-stdbad-alloc-w?noredirect=1#comment114427227_64715888
 */

#include <iostream>
#include <iterator>
#include "artist.h"
#include "person.h"
#include "group.h"
#include "song.h"
#include "metadata.h"

using namespace std;

int main()
{
    // Those are imaginary artists and an imaginary group
    Person darbekji("Moez");
    Person tabel("Sofiene");
    Person pianiste("Rostom");
    Person zakar("Amine");

    Group tbb("TheBadBoys");

    tbb.addMember(&darbekji);
    tbb.addMember(&tabel);
    tbb.addMember(&pianiste);
    tbb.addMember(&zakar);

    cout << darbekji.info() << endl;
    cout << tbb.info() << endl << endl;

    Song bara_nayek;
    bara_nayek.artist(&tbb);
    bara_nayek.title("bara hakeka");
    bara_nayek.metadata()->init(253,1980,Genre::Funk);

    Song chwitni;
    chwitni.artist(&tbb);
    chwitni.title("bled lebheyem");
    chwitni.metadata()->init(155,2001,Genre::Soul);

    Song loubya;
    loubya.artist(&tbb);
    loubya.title("zaboubeya");
    loubya.metadata()->init(74,2004,Genre::Rock);

    tbb.addSong(&bara_nayek);
    tbb.addSong(&chwitni);
    tbb.addSong(&loubya);

    // I get segmentation fault when using iterator. Why though ? :(
    /*vector <Song *>::iterator itr;
    for ( itr = bhn.songs().begin(); itr != bhn.songs().end(); itr++)
    {
        cout << (*itr)->info() << endl;
    }*/

    for (Song* value : tbb.songs())
    {
        cout << value->info() << endl;
    }

    return 0;
}
