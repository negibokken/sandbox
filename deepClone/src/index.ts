export function deepClone(object: any): any {
  const newObject: any = Object.assign({}, object);
  Object.keys(newObject)
    .filter((k: string) => { return typeof newObject[k] === 'object'; } )
    .forEach((k: string) => { return newObject[k] = deepClone(newObject[k]); });
  return newObject;
};
