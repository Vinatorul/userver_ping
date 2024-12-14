# Start via `make test-debug` or `make test-release`
async def test_v1_ping(service_client):
    response = await service_client.post(
        '/v1/ping',
    )
    assert response.status == 200
    assert response.text == '1'

    response = await service_client.post(
        '/v1/ping',
    )
    assert response.status == 200
    assert response.text == '2'


async def test_v1_stat(service_client):
    response = await service_client.post(
        '/v1/ping',
    )
    assert response.status == 200

    counter = response.text

    response = await service_client.post(
        '/v1/stat',
    )
    assert response.status == 200
    assert response.text == counter

