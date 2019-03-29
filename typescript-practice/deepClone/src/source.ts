import {deepClone} from './index';

let a: any = {
  a: 'aaa',
  b: {
    c: 'cccc',
    d: 'dddd',
  },
  e: {
    f: 'ffff',
    g: 'gggg',
    h: {
      i: 'iiii',
      j: 'jjjj',
    }
  }
};

let b: any = deepClone(a);

b.b = 'aaaaa';

console.log('before object');
console.log(a);
console.log('--------------');
console.log('after object');
console.log(b);
