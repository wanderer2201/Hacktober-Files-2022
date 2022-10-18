const favorites = ["Seafood", "Salad", "Nugget", "Soup"];
 
console.log(favorites);
/* output
[ 'Seafood', 'Salad', 'Nugget', 'Soup' ]
*/

//! iterable object/ spread operator
console.log(...favorites)
//* as same as :
console.log(favorites[0], favorites[1], favorites[2], favorites[3]);
/* output
Seafood Salad Nugget Soup
*/

// merging 2 arrays without spread operator
const favoritess = ["Seafood", "Salad", "Nugget", "Soup"];
const others = ["Cake", "Pie", "Donut"];

const allFavorites = [favoritess, others];

console.log(allFavorites);

/* output
[
  [ 'Seafood', 'Salad', 'Nugget', 'Soup' ],
  [ 'Cake', 'Pie', 'Donut' ]
]
*/

//! merging 2 arrays with spread operator
const favoritesss = ["Seafood", "Salad", "Nugget", "Soup"];
const othersss = ["Cake", "Pie", "Donut"];

const allFavoritess = [...favoritesss, ...othersss];

console.log(allFavorites);

/* output
[ 'Seafood', 'Salad', 'Nugget', 'Soup', 'Cake', 'Pie', 'Donut' ]
*/

//! merging 2 literal objects
const obj1 = { firstName: 'Obi-Wan', age: 30 };
const obj2 = { lastName: 'Kenobi', gender: 'M' };

const newObj = { ...obj1, ...obj2 };

console.log(newObj);

/* output
{ firstName: 'Obi-Wan', age: 30, lastName: 'Kenobi', gender: 'M' }
*/
