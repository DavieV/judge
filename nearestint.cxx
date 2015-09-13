#include <algorithm>
#include <iterator>
#include <limits>
#include <set>
#include <vector>
#include <type_traits>
#include <iostream>

using VALUE_TYPE = int;

template <
    template <typename, typename...> class RetContainer,
    typename Container,
    typename ContainerType = typename std::remove_reference<Container>::type
    >
auto find_closest(
    Container& c,                                   // Container
    typename ContainerType::key_type const& search  // value to search for
    ) ->
    RetContainer<decltype(c.begin())>
{
    using std::numeric_limits;
    using key_type = typename ContainerType::key_type;
    using iterator_type = decltype(c.begin());
    using ret_type = RetContainer<iterator_type>;

    ret_type retval;

    auto&& er = c.equal_range(search);

    if ((er.first != er.second) && (*er.first == *(std::prev(er.second)))) {
        retval.emplace_back(std::move(er.first));
        return retval;
    }

    auto lt = er.first;
    auto lt_diff = numeric_limits<key_type>::max();
    bool lt_exists = false;
    if (lt != c.begin())
    {
        --lt;
        lt_diff = search - *lt;
        lt_exists = true;
    }

    auto gt = er.second;
    auto gt_diff = numeric_limits<key_type>::max();
    bool gt_exists = false;
    if (gt != c.end())
    {
        gt_diff = *gt - search;
        gt_exists = true;
    }

    auto&& compare = c.key_comp();

    // If lt_exists && lt_diff <= gt_diff...
    // NOTE: SWO semantics is used here...
    if (lt_exists && (compare(lt_diff,gt_diff)
                || !compare(lt_diff,gt_diff) && !compare(gt_diff,lt_diff)))
        retval.emplace_back(std::move(lt));

    // If gt_exists && gt_diff <= lt_diff...
    // NOTE: SWO semantics is used here...
    if (gt_exists && (compare(gt_diff,lt_diff)
                || !compare(gt_diff,lt_diff) && !compare(lt_diff,gt_diff)))
        retval.emplace_back(std::move(gt));

    return retval;
}


int main()
{
    using namespace std;

    vector<VALUE_TYPE> values;

    // Read in values from standard input...
    copy(
        istream_iterator<VALUE_TYPE>(cin),
        istream_iterator<VALUE_TYPE>(),
        back_inserter(values)
    );

    // Gobble up all remaining characters until end of line...
    cin.clear();
    if (cin)
    {
        string line;
        getline(cin, line);
    }
    else
        return 1;

    // Build set and multiset on input values...
    set<VALUE_TYPE> const s{ values.begin(), values.end() };
    multiset<VALUE_TYPE> const ms{ values.begin(), values.end() };

    for (int search_value; cin >> search_value; )
    {
        // set results...
        auto&& s_closest = find_closest<std::vector>(s, search_value);

        cout << "For set, ";
        switch (s_closest.size())
        {
            case 2:
                cout << "the closest values are " << *s_closest.front() 
                    << " and " << *s_closest.back() << endl;
                break;

            case 1:
                cout << "the closest value is " << *s_closest.front() << endl;
                break;

            default:
                cout << "there is no closest value." << endl;
        }

        // multiset results...
        auto&& ms_closest = find_closest<std::vector>(ms, search_value);

        cout << "For multiset, ";
        switch (ms_closest.size())
        {
            case 2:
                cout << "the closest values are " << *ms_closest.front() 
                    << " and " << *ms_closest.back() << endl;
                break;

            case 1:
                cout << "the closest value is " << *ms_closest.front() << endl;
                break;

            default:
                cout << "there is no closest value." << endl;
        }

        cout << endl;
    }
}

