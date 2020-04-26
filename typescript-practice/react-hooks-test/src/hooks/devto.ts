import { useEffect, useState } from 'react';

export function useArticles(page?: string, tag?: string, username?: string) {
  const [articles, setArticles] = useState<{ title: string }[]>([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState();

  useEffect(() => {
    let apiUrl = 'https://dev.to/api/articles?';
    const params = [];
    if (page) params.push(`page=${page}`);
    if (tag) params.push(`tag=${tag}`);
    if (username) params.push(`username=${username}`);
    apiUrl += params.join('&');
    setLoading(true);
    setError(undefined);
    fetch(apiUrl)
      .then((res) => res.json())
      .then((data) => {
        setLoading(false);
        setArticles(data);
      })
      .catch((error) => {
        setLoading(false);
        setError(error);
      });
  }, [page, tag, username]);
  return { articles, loading, error };
}
