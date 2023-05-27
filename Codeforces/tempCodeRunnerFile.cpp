 for (ll i = 0; i < n - 1;i++){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }